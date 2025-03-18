#include "BattleManager.h"
#include <random>
#include <chrono>
#include <thread>

void BattleManager::startBattle(unique_ptr<Character>& player1, unique_ptr<Character>& player2) {
	cout << "���� ����" << player1->getName() << " vs " << player2->getName() << endl;
	//���� �帧 :
	//���� ������ ���� ������ ����(ù ��° ������)�� �������� �����Ѵ�.
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> firstTurn(0, 1);
	uniform_int_distribution<> attackType(0, 100);

	bool firstAttack = firstTurn(gen);
	 
	//	�� ĳ������ ü���� 0�� �Ǹ� ���� ����
	while (player1->isAlive() && player2->isAlive()) {
		player1->showStatus();
		player2->showStatus();
		
		//	���� ó��(try - catch)
		try {
			if (firstAttack) {
				//	ù ��° ĳ���Ͱ� ����
				//���� ������ ���� 70 % Ȯ���� �⺻ ����, 30 % Ȯ���� Ư�� ����(���� �߻� ����)
				if (attackType(gen) < 70) player1->attack(*player2);
				else player1->specialAttack(*player2);

				this_thread::sleep_for(chrono::milliseconds(1000));

				//	�� ��° ĳ���Ͱ� ��������� �ݰ�
				if (!player2->isAlive()) break;

				if (attackType(gen) < 70) player2->attack(*player1);
				else player2->specialAttack(*player1);

				//	���� ����� �����̸� �߰��Ͽ� �� �ڿ������� ������ �����Ѵ�.
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
			//	���� ���� �� ���� �Ұ�
			cout << e.what() << endl;
		}
		cout << "---------------------------------" << endl;
	}

	cout << (player1->isAlive() ? player1->getName() : player2->getName()) << "��(��) �¸��߽��ϴ�." << endl;
}
