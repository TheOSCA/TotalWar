#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>

#include "allegro/allegro.h"

#include "Ressources.h"
#include "Map.h"
#include "City.h"

using namespace std;

SpriteMap menu_sprites;
SpriteMap bg_sprites;
SpriteMap logo_sprites;
SpriteMap cursor_sprites;
vector<Sprite> boutons;
Sprite background_sprite;
Sprite logo_sprite;
Sprite normal_cursor_sprite;

unsigned btn_quit_id;

unsigned normal_cursor;

void redraw_start(Allegro* allegro, float fps){
	allegro->clearScreen();
	
	int l = allegro->getDisplayWidth();
	int h = allegro->getDisplayHeight();
	
	float L_logo = 0.5*float(l);
	float h_logo = L_logo*(426.-14.)/(1658.-150.);
	
	background_sprite.drawSprite(0, 0, l, h);
	allegro->draw_rectangle(0, 0, l, h, Color(0, 0, 0, 100).toAllegro(), 1, true);
	
	logo_sprite.drawSprite(l/2, 100, L_logo, h_logo, true);
	
	//normal_cursor_sprite.drawSprite(0, 0);
}

void btn_clicked(Allegro* allegro, Button* btn){
	if(btn->id == btn_quit_id){
		allegro->quit();
	}
}

int main(int argc, char** args){
	
	/* INITIALISATION */
	
	Allegro::init();
	
	Allegro startscreen;
	
	startscreen.createWindow(60, 1080, 720, ALLEGRO_WINDOWED);
	
	/* LOADING SPRITES */
	
	menu_sprites = SpriteMap("assets/menu.png");
	bg_sprites = SpriteMap("assets/calendrier-azteque.png");
	logo_sprites = SpriteMap("assets/logo.png");
	cursor_sprites = SpriteMap("assets/cursor.png");
	
	for(unsigned i=0; i<3; i++){
		boutons.push_back(menu_sprites.getSprite(0, i*(27+2), 75, 28));
	}
	background_sprite = bg_sprites.getSprite(106, 61, 1169-106, 672-61);
	logo_sprite = logo_sprites.getSprite(150, 14, 1658-150, 426-14);
	normal_cursor_sprite = cursor_sprites.getSprite(11, 7, 187-11, 206-7);
	
	/* CREATING GUI USING GUI API */
	
	// Bouton pour quitter
	unsigned btn_quit_index = startscreen.getGUI()->newBtn("Quit", startscreen.getDisplayWidth()/2-125, 400, 80, 250, &btn_clicked);
	startscreen.getGUI()->setBtnSprites(0, boutons[0], boutons[2], boutons[1]);
	btn_quit_id = startscreen.getGUI()->getBtnId(btn_quit_index);
	
	// Curseur
	normal_cursor = startscreen.getGUI()->newCursor(normal_cursor_sprite, "Normal", 40);
	startscreen.getGUI()->setCursor(normal_cursor);
	startscreen.setCursorVisibility(false);
	
	/* BINDING EVENTS FUNCTIONS */
	
	startscreen.setRedrawFunction(&redraw_start);
	
//	City test(100, Coos(10, 10), Gold(100));
//	
//	test.production += 10;
//	
//	cout << test.production;
	
	Allegro::startLoop();
}