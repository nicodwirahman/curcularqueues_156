#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number:";
		cin >> num;
		cout << endl;

		//cek apa antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue pverflow\n";
			return;
		}

		//cek apakah antrian penuh
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika REAR berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		// cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is:" << queue_array[FRONT] << "\n";

		//cek jika antrian hanya memliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			// jike elemen yang dihapus berada diposisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

		void display() {
			int FRONT_position = FRONT;
			int REAR_position = REAR;

			//cek antrian kosong
			if (FRONT == -1) {
				cout << "queue is Empty\n";
					return;
	}

			cout << "\nElements is the queue are...\n";

			//jika FRONT_position <= rear_position, literasi dari front hingga rear
			if (FRONT_position <= REAR_position) {
				while (FRONT_position <= REAR_position) {
					cout << queue_array[FRONT_position] << " ";
					FRONT_position++;
				}
				cout << endl;
				}