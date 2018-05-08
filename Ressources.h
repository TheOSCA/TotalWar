#ifndef RESSOURCES_H
#define RESSOURCES_H

class Ressource {
protected:
	int type;
	int quantite = 0;
	std::string nom;
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
	
	 friend std::ostream& operator<<(std::ostream& os, const Ressource& r){
		 os << r.quantite << " " << r.nom;
	 } 
};

class Gold : public Ressource {
public:
	
	Gold(int n = 0){
		type = 0;
		quantite = n;
		nom = "Or";
	}
};

#endif