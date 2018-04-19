
class X{
public:
	friend class Y;
	int y(){
		return i++;
	}
	int z(){
		return i=i+5;
	}
	int g(){
	return i=i+10;}
	int geti(){
		return i;}
private:
	 static int i;
};
int X::i=0;
class Y{
public:
	int g();
private:
	X a;
};
int Y::g(){return a.y();};
class Z{
public:
	friend class X;
	int f(){return b.z();}
private:
	X b;

};
void h(){X c;
c.g();};


	