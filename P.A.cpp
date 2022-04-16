#include <bangtal.h>
#include <stdio.h>
#include <time.h>

SceneID scene1, scene2, scene3, scene4, scene5;
ObjectID start,end, next1, next2, left1, right1, left2, right2, left3, right3, door1, door2, key, box, foot1, foot2, foot3, police, pot;
TimerID timer1;

void timerCallback(TimerID timer) {
	if (timer == timer1) {
		endGame();
	}
}

void endGame(bool success) {
	if (success) {
		showMessage("감옥탈출 성공!!");
	}
	else {
		showMessage("감옥탈출 실패ㅜ");
	}

}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == end) {
		endGame();
	}
	else if (object == start) {
		enterScene(scene2);
		showMessage("당신은 억울하게 감옥에 갇혔습니다 \n 자유를 위해 탈출하세요!");
		showObject(next1);
		startTimer(timer1);
	}
	if (object == next1) {
		enterScene(scene3);
	}
	else if (object == next2) {
		enterScene(scene3);
	}
	if (object == left1) {
		enterScene(scene4);
		showMessage("발자국을 지우세요!");
	}
	else if (object == right1) {
		enterScene(scene5);
		showMessage("교도관을 물리치세요!");
	}
	if (object == left2) {
		enterScene(scene5);
	}
	else if (object == right2) {
		enterScene(scene3);
	}
	if (object == left3) {
		enterScene(scene3);
	}
	else if (object == right3) {
		enterScene(scene4);
	}
	
	if (object == pot) {
		pickObject(pot);
		showMessage("무기 획득!");
	}
	else if (object == police) {
		if (pot == getHandObject())
		{
			hideObject(police);
		}
	}
	if (object == key) {
		pickObject(key);
	}
	else if (object == door1) {
		if (key == getHandObject())
		{
			setObjectImage(door1, "문-오른쪽-열림.png");
			endGame();
		}
		else
		{
			showMessage("열쇠가 필요해");
		}

	}
	if (object == box) {

		hideObject(box);
		showObject(key);

	}
	if (object == foot1) {
		showMessage("발자국을 지우세요!");
		hideObject(foot1);
	}
	if (object == foot2) {
		showMessage("발자국을 지우세요!");
		hideObject(foot2);
	}
	if (object == foot3) {
		showMessage("발자국을 지우세요!");
		hideObject(foot3);
	}
}


	



int main() {

	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	scene1 = createScene("감옥탈출", "prison.png");
	scene2 = createScene("감옥탈출", "person.png");
	scene3 = createScene("감옥탈출", "room1.png");
	scene4 = createScene("감옥탈출", "room2.png");
	scene5 = createScene("감옥탈출", "room3.png");
	


	start = createObject("start.png");
	locateObject(start, scene1, 695, 150);
	showObject(start);

	end = createObject("end.png");
	locateObject(end, scene1, 695, 110);
	showObject(end);

	next1 = createObject("next.png");
	locateObject(next1, scene2, 1150, 600);
	scaleObject(next1,0.2f);

	next2 = createObject("next.png");
	locateObject(next2, scene3, 1150, 600);
	scaleObject(next2, 0.2f);

	left1 = createObject("left.png");
	locateObject(left1, scene3, 35, 345);
	showObject(left1);

	right1 = createObject("right.png");
	locateObject(right1, scene3, 1170, 345);
	showObject(right1);

	left2 = createObject("left.png");
	locateObject(left2, scene4, 35, 345);
	showObject(left2);

	right2 = createObject("right.png");
	locateObject(right2, scene4, 1170, 345);
	showObject(right2);

	left3 = createObject("left.png");
	locateObject(left3, scene5, 35, 345);
	showObject(left3);

	right3 = createObject("right.png");
	locateObject(right3, scene5, 1170, 345);
	showObject(right3);

	door1 = createObject("문-오른쪽-닫힘.png");
	locateObject(door1, scene5, 800, 270);
	showObject(door1);

	box = createObject("box.png");
	locateObject(box, scene3, 250, 64);
	showObject(box);

	key = createObject("열쇠.png");
	locateObject(key, scene3, 250, 100);
	scaleObject(0.2f, key);
	hideObject(key);
	
	foot1 = createObject("foot.png");
	locateObject(foot1, scene4, 250, 100);
	scaleObject(0.1f, foot1);
	showObject(foot1);

	foot2 = createObject("foot.png");
	locateObject(foot2, scene4, 550, 150);
	scaleObject(0.1f, foot2);
	showObject(foot2);

	foot3 = createObject("foot.png");
	locateObject(foot3, scene4, 800, 200);
	scaleObject(0.1f, foot3);
	showObject(foot3);

	police = createObject("police.png");
	locateObject(police, scene5, 900, 200);
	showObject(police);
	
	pot = createObject("화분.png");
	locateObject(pot, scene5, 300, 150);
	showObject(pot);

	timer1 = createTimer(120.0f);
	showTimer(timer1);


	startGame(scene1);
	

}