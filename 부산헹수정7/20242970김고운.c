#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

// 파라미터
#define LEN_MIN 15   //기차 길이
#define LEN_MAX 50
#define STM_MIN 0    //마동석 체력
#define STM_MAX 5
#define PROB_MIN 10  //확률
#define PROB_MAX 90
#define AGGRO_MIN 0  //어그로 범위
#define AGGRO_MAX 5  

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// 마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2



int main(void) {
	srand((unsigned int)time(NULL));

	printf("     --------    ------\n");
	printf("            +    |      +\n");
	printf("          +      |    +\n");
	printf("        +        |    +\n");
	printf("      +          |      +\n");
	printf("     --------    ------\n");
	printf(" \n\n\n");
	Sleep(2000);

	// 기차 길이
	int length;
	do {
		printf("train length(%d~%d)>> ", LEN_MIN, LEN_MAX);
		if (scanf_s("%d", &length) != 1) {
			while (getchar() != '\n');
			continue;
		}
		if (length < LEN_MIN || length > LEN_MAX) {
			continue;
		}
		break;
	} while (1);


	// 마동석 체력
	int stm;
	do {
		printf("madongseok stamina(%d~%d)>> ", STM_MIN, STM_MAX);
		if (scanf_s("%d", &stm) != 1) {
			while (getchar() != '\n');
			continue;
		}
		if (stm < STM_MIN || stm > STM_MAX) {
			continue;
		}
		break;
	} while (1);

	// 확률
	int prob;
	do {
		printf("percentile probability 'p'(%d~%d)>> ", PROB_MIN, PROB_MAX);
		if (scanf_s("%d", &prob) != 1) {
			while (getchar() != '\n');
			continue;
		}
		if (prob < PROB_MIN || prob > PROB_MAX) {
			continue;
		}
		break;
	} while (1);
	printf("\n\n");



	if (length >= LEN_MIN && length <= LEN_MAX) {
		if (prob >= PROB_MIN && prob <= PROB_MAX);
		int i;
		for (i = 0; i < length; i++) { // 1번째 줄
			printf("#");
		}
		printf("\n");


		for (i = 0; i < length; i++) { // 2번째 줄
			if (i == 0) {
				printf("#");
			}

			else if (i == (length - 1)) {
				printf("#");
			}

			else if (i == (length - 2)) {
				printf("M");
			}

			else if (i == (length - 3)) {
				printf("Z");
			}

			else if (i == (length - 6)) {
				printf("C");
			}

			else {
				printf(" ");
			}
		}
		printf("\n");


		for (i = 0; i < length; i++) { // 3번째 줄
			printf("#");
		}
		printf("\n\n\n");


	}
	// 변수 선언 
	int C = length - 6;
	int Z = length - 3;
	int M = length - 2;
	int K = C;
	int T = Z;
	int P = M;
	int i;
	int x = 0;
	int move;

	int citizen_aggro = 1;
	int N = citizen_aggro;

	int madongseok_aggro = 1;
	int E = madongseok_aggro;

	while (1) {
		x++;
		int citizen = rand() % 100;
		int zombie = rand() % 100;
		int madongseok = rand() % 100;

		if (citizen <= (100 - prob)) {
			C--;
		}

		if (x % 2 != 0) {
			if (zombie <= prob) {
				Z--;
			}
		}
		else {}

		// 열차
		for (i = 0; i < length; i++) { // 1번째 줄
			printf("#");
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 2번째 줄
			if (i == 0) {
				printf("#");
			}

			else if (i == (length - 1)) {
				printf("#");
			}

			else if (i == M) {
				printf("M");
			}

			else if (i == Z) {
				printf("Z");
			}

			else if (i == C) {
				printf("C");
			}

			else {
				printf(" ");
			}
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 3번째 줄
			printf("#");
		}
		printf("\n\n\n");




		// 시민 상태 출력
		if (C != K) {
			citizen_aggro++;
			if (citizen_aggro > AGGRO_MAX) citizen_aggro = AGGRO_MAX;
			printf("citizen: %d -> %d (aggro: %d -> %d)\n", K, C, N, citizen_aggro);
		}
		else if (C == K) {
			citizen_aggro--;
			if (citizen_aggro < AGGRO_MIN) citizen_aggro = AGGRO_MIN;
			printf("citizen: stay %d (aggro: %d -> %d)\n", K, N, citizen_aggro);
		}
		N = citizen_aggro;

		// 좀비 상태 출력

		if (Z != T) {
			printf("zombie: %d -> %d\n", T, Z);
		}

		else if (Z == T) {
			if (x % 2 == 1) {
				printf("zombie: stay %d\n", T);
			}
			else {
				printf("zombie: stay %d (cannot move)\n", T);
			}
		}

		else if (Z == (C + 1)) {
			printf("zombie: stay %d\n", T);
		}
		printf("\n\n");



		// 마동석 상태 입력
		while (1) {
			printf("madongseok move(0:stay, 1:left)>> ");
			scanf_s("%d", &move);
			if (move == 1 || move == 0) {
				break;
			}
			if (M == (Z + 1)) {
				printf("madongseok move(0:stay)>> ");
				scanf_s("%d", &move);
				if (move == 0) {
					break;
				}
			}
		}

		// 마동석 이동
		if (move == 1) {
			M--;
		}
		else if (move == 0) {
			M == P;
		}

		// 열차
		for (i = 0; i < length; i++) { // 1번째 줄
			printf("#");
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 2번째 줄
			if (i == 0) {
				printf("#");
			}

			else if (i == (length - 1)) {
				printf("#");
			}

			else if (i == M) {
				printf("M");
			}

			else if (i == Z) {
				printf("Z");
			}

			else if (i == C) {
				printf("C");
			}

			else {
				printf(" ");
			}
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 3번째 줄
			printf("#");
		}
		printf("\n\n\n");


		// 마동석 위치 출력 
		if (M != P) {
			madongseok_aggro++;
			if (madongseok_aggro > AGGRO_MAX) madongseok_aggro = AGGRO_MAX;
			printf("madongseok: %d -> %d(aggro: %d -> %d, stamina: %d)", P, M, E, madongseok_aggro, stm);
		}
		else if (M == P) {
			madongseok_aggro--;
			if (madongseok_aggro < AGGRO_MIN) madongseok_aggro = AGGRO_MIN;
			printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)", P, E, madongseok_aggro, stm);
		}
		E = madongseok_aggro;
		printf("\n\n\n");


		// 시민 행동
		if (C == (length - (length - 1))) {
			printf("YOU WIN!...");
			break;
		}
		else { printf("citizen does nothing.\n"); }
		int S = stm;
		// <좀비 공격> 둘다 인접
		if (Z == (C + 1) && Z == (M - 1)) {
			if (citizen_aggro > madongseok_aggro) {
				break;
				printf("GAME OEVER! citizen dead...\n");
			}
			else {
				stm--;
				printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n", citizen_aggro, madongseok_aggro, S, stm);
				if (stm == STM_MIN) {
					break;
				}

			}
		}
		// <좀비 공격> 시민만 인접
		else if (Z == (C + 1)) {
			break;
			printf("GAME OEVER! citizen dead...\n");
		}
		// <좀비 공격> 마동석만 인접
		else if (Z == (M - 1)) {
			stm--;
			if (stm == STM_MIN) {
				break;
			}
		}
		// 둘 다 인접 X
		else {
			printf("zombie attacked nobody.\n");
		}

		// 마동석 행동
		int madongseok_action;
		if (M == (Z + 2)) {  // 인접하지 않은 경우
			while (1) {
				printf("madongseok action(0.rest, 1.provoke)>> ");
				scanf_s("%d", &madongseok_action);
				if (madongseok_action == 0 || madongseok_action == 1) {
					break;
				}
			}
			printf("\n\n");
			if (madongseok_action == 0) {
				printf("madongseok rests...\n");
				madongseok_aggro--;
				stm++;
				if (AGGRO_MIN > madongseok_aggro) madongseok_aggro = AGGRO_MIN;
				if (STM_MAX < stm) stm = STM_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, E, madongseok_aggro, S, stm);
			}
			else if (madongseok_action == 1) {
				printf("madongseok provoked zombie...\n\n");
				madongseok_aggro == AGGRO_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, E, madongseok_aggro, S); 
			}
		}

		else if (M == (Z + 1)) {  // 인접한 경우
			while (1) {
				printf("madongseok action(0.rest, 1.provoke, 2. pull)>> ");
				scanf_s("%d", &madongseok_action);
				if (madongseok_action == 0 || madongseok_action == 1 || madongseok_action == 2) {
					break;
				}
			}
			printf("\n\n");
			if (madongseok_action == 0) {
				printf("madongseok rests...\n");
				madongseok_aggro--;
				stm++;
				if (madongseok_aggro < AGGRO_MIN) madongseok_aggro = AGGRO_MIN;
				if (stm > STM_MAX) stm = STM_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, E, madongseok_aggro, S, stm);
			}
			else if (madongseok_action == 1) {
				printf("madongseok provoked zombie...\n");
				madongseok_aggro == STM_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, E, madongseok_aggro, S);
			}
			else if (madongseok_action == 2) {
				if (madongseok <= (100 - prob)) {
					printf("madongseok pulled zombie... Next trun, it can't move\n");
					madongseok_aggro + 2;
					stm--;
					if (madongseok_aggro > AGGRO_MAX) madongseok_aggro = AGGRO_MAX;
					if (stm < STM_MIN) stm = STM_MIN;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, E, madongseok_aggro, S, stm);
					M == P;
				}
				else {
					printf("madongseok failed to pull zombie\n");
					madongseok_aggro + 2;
					stm--;
					if (madongseok_aggro > AGGRO_MAX) madongseok_aggro = AGGRO_MAX;
					if (stm < STM_MIN) stm = STM_MIN;
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, E, madongseok_aggro, S, stm);
				}
			}
		}
		printf("\n\n\n");



		K = C;
		T = Z;
		P = M;


	}

	return 0;
}















