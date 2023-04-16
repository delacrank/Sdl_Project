#ifndef __GAME_OBJECT__H__
#define __GAME_OBJECT__H__

class GameObject {

public:

	GameObject();
	void draw() {}
	void update() {}
	void clean() {}

protected:
	int m_x;
	int m_y;

};

#endif // !__GAME_OBJECT__H__

