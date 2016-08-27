//
// Created by FKS143 on 2016/8/27.
//

#ifdef __cplusplus
extern "C" {
#endif

class GameManager
{
public:
	static GameManager * getInstance();
	
	void init();
	void step();
	void resize(int width, int height);
	
private:
	GameManager();

private:
	static GameManager * instance;
};

#ifdef __cplusplus
extern "C" {
#endif
