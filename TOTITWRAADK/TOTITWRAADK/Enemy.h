#ifndef ENEMY_HEADER
#define ENEMY_HEADER
class Enemy
{	
public:
	Enemy();
	~Enemy();

	int speed, health, damage;
	int enemyCount;
	void movement();
	void update(); 
private:
	
};
#endif
