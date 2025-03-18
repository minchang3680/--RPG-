#include "BattleManager.h"
#include <random>
#include <chrono>
#include <thread>

void BattleManager::startBattle(unique_ptr<Character>& player1, unique_ptr<Character>& player2) {
	cout << "전투 시작" << player1->getName() << " vs " << player2->getName() << endl;
	//전투 흐름 :
	//난수 생성을 통해 전투의 선공(첫 번째 공격자)을 랜덤으로 결정한다.
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> firstTurn(0, 1);
	uniform_int_distribution<> attackType(0, 100);

	bool firstAttack = firstTurn(gen);
	 
	//	한 캐릭터의 체력이 0이 되면 전투 종료
	while (player1->isAlive() && player2->isAlive()) {
		player1->showStatus();
		player2->showStatus();
		
		//	예외 처리(try - catch)
		try {
			if (firstAttack) {
				//	첫 번째 캐릭터가 공격
				//난수 생성을 통해 70 % 확률로 기본 공격, 30 % 확률로 특수 공격(예외 발생 가능)
				if (attackType(gen) < 70) player1->attack(*player2);
				else player1->specialAttack(*player2);

				this_thread::sleep_for(chrono::milliseconds(1000));

				//	두 번째 캐릭터가 살아있으면 반격
				if (!player2->isAlive()) break;

				if (attackType(gen) < 70) player2->attack(*player1);
				else player2->specialAttack(*player1);

				//	전투 진행시 딜레이를 추가하여 더 자연스러운 전투를 연출한다.
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
			else {
				if (attackType(gen) < 70) player2->attack(*player1);
				else player2->specialAttack(*player1);

				this_thread::sleep_for(chrono::milliseconds(1000));

				if (!player2->isAlive()) break;

				if (attackType(gen) < 70) player1->attack(*player2);
				else player1->specialAttack(*player2);

				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
		catch (const exception& e) {
			//	마나 부족 시 공격 불가
			cout << e.what() << endl;
		}
		cout << "---------------------------------" << endl;
	}

	cout << (player1->isAlive() ? player1->getName() : player2->getName()) << "이(가) 승리했습니다." << endl;
}
