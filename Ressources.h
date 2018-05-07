#ifndef RESSOURCES_H
#define RESSOURCES_H

class Ressource {
protected:
	int type;
	int quantite = 0;
public:
	int getType(){
		return type;
	}
	
	Ressource(int quantite = 0){
		this->quantite = quantite;
	}
	
	void operator+=(int n){
		this->quantite += n;
	}
	
	void operator +=(Ressource const& r){
		if(r.type == this->type)
			this->quantite += r.quantite;
		else
			throw(666);
	}
};

class Gold : protected Ressource {
private:
	int type = 0;
public:
	
	Gold(int n = 0){
		quantite = n;
	}
};

#endif