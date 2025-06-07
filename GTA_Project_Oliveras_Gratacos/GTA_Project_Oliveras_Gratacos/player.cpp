#include"player.h"
#include"mapa.h"
#include"lecturaArchivo.h"
Player::Player()
{
	LecturaArchivo archivo;

	hp = archivo.GetHpCJ();
	position.X = 4;
	position.Y = 2;
	mony = 0;
	moveInput = Actions::UP;
	lastMoveInput = Actions::UP;
	CurrentIsland = 1;
	Damage = archivo.GetPowerCJ();
	canMove = true;
	canEnterCar = false;
	inCar = false;
	vista = 5;
}



Player::~Player() {

}

void Player::stopNPC(peaton& peaton) {
	for (int i = position.Y - 1; i < position.Y + 1; i++) {
		for (int j = position.X - 1; j < position.X + 1; j++) {
			if (peaton.GetPosition().Y == i && peaton.GetPosition().X == j) {
				peaton.SetCanMove(false);
				return;
			}
		}
	}
	peaton.SetCanMove(true);
}
void Player::stopBS(BigSmoke& BS) {
	for (int i = position.Y - 1; i < position.Y + 1; i++) {
		for (int j = position.X - 1; j < position.X + 1; j++) {
			if (BS.GetPosition().Y == i && BS.GetPosition().X == j) {
				BS.SetCanMove(false);
				return;
			}
		}
	}
	BS.SetCanMove(true);
}

void Player::SeeIfCanMove(Mapa mapa, bool& InGame, bool& EndGame, std::vector<peaton>& peatones) {
	int X = position.X;
	int Y = position.Y;
	if (moveInput == Actions::UP) {
		if (mapa.getCella(X, Y - 1) == Cella::VACIA ) {
			canMove = true;
			
		}
		else if (mapa.getCella(X, Y - 1) == Cella::PEAJE) {
			EndGame = true;
			InGame = false;
		}
		else if (mapa.getCella(X, Y - 1) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if(CurrentIsland == 2){
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else if (mapa.getCella(X, Y - 1) == Cella::PEATON && inCar) {
			for (int i = 0; i < peatones.size(); i++)
			{
				if (peatones[i].GetPosition().X == X && peatones[i].GetPosition().Y == Y - 1)
				{
					peatones[i].DamagePeaton(1000);
					peatones[i].SeeIFDead();
					peatones[i].RespawnPeaton(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), i, mapa);
				}
			}
			mapa.SetCella(X, Y - 1, Cella::VACIA);
			
			bool aux2 = true;
			while (aux2)
			{
				int aux = rand() % 4 + 1;
				switch (aux) {
				case 1:
					if (mapa.getCella(X, Y - 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y - 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
						break;
				case 2:
					if (mapa.getCella(X, Y + 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y + 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 3:
					if (mapa.getCella(X - 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X - 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 4:
					if (mapa.getCella(X + 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X + 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				}
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::DOWN) {
		if (mapa.getCella(X, Y + 1) == Cella::VACIA ) {
			canMove = true;
			
		}
		else if (mapa.getCella(X, Y + 1) == Cella::PEAJE) {
			EndGame = true;
		}
		else if (mapa.getCella(X, Y + 1) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if (CurrentIsland == 2) {
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else if (mapa.getCella(X, Y + 1) == Cella::PEATON && inCar) {
			for (int i = 0; i < peatones.size(); i++)
			{
				if (peatones[i].GetPosition().X == X && peatones[i].GetPosition().Y == Y + 1)
				{
					peatones[i].DamagePeaton(1000);
					peatones[i].SeeIFDead();
					peatones[i].RespawnPeaton(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), i, mapa);
				}
			}
			mapa.SetCella(X, Y + 1, Cella::VACIA);

			bool aux2 = true;
			while (aux2)
			{
				int aux = rand() % 4 + 1;
				switch (aux) {
				case 1:
					if (mapa.getCella(X, Y - 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y - 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 2:
					if (mapa.getCella(X, Y + 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y + 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 3:
					if (mapa.getCella(X - 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X - 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 4:
					if (mapa.getCella(X + 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X + 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				}
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::RIGHT) {
		if (mapa.getCella(X + 1, Y) == Cella::VACIA ) {
			canMove = true;
			
		}
		else if (mapa.getCella(X + 1, Y) == Cella::PEAJE) {
			EndGame = true;
			InGame = false;
		}
		else if (mapa.getCella(X + 1, Y) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if (CurrentIsland == 2) {
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else if (mapa.getCella(X + 1, Y) == Cella::PEATON && inCar) {
			for (int i = 0; i < peatones.size(); i++)
			{
				if (peatones[i].GetPosition().X == X + 1 && peatones[i].GetPosition().Y == Y)
				{
					peatones[i].DamagePeaton(1000);
					peatones[i].SeeIFDead();
					peatones[i].RespawnPeaton(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), i, mapa);
				}
			}
			mapa.SetCella(X + 1, Y, Cella::VACIA);

			bool aux2 = true;
			while (aux2)
			{
				int aux = rand() % 4 + 1;
				switch (aux) {
				case 1:
					if (mapa.getCella(X, Y - 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y - 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 2:
					if (mapa.getCella(X, Y + 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y + 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 3:
					if (mapa.getCella(X - 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X - 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 4:
					if (mapa.getCella(X + 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X + 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				}
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::LEFT) {
		if (mapa.getCella(X - 1,Y) == Cella::VACIA ) {
			canMove = true;
			
		}
		else if (mapa.getCella(X - 1, Y) == Cella::PEAJE) {
			EndGame = true;
			InGame = false;
		}
		else if (mapa.getCella(X - 1, Y) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if (CurrentIsland == 2) {
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else if (mapa.getCella(X - 1, Y) == Cella::PEATON && inCar) {
			for (int i = 0; i < peatones.size(); i++)
			{
				if (peatones[i].GetPosition().X == X - 1 && peatones[i].GetPosition().Y == Y)
				{
					peatones[i].DamagePeaton(1000);
					peatones[i].SeeIFDead();
					peatones[i].RespawnPeaton(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), i, mapa);
				}
			}
			mapa.SetCella(X - 1, Y, Cella::VACIA);

			bool aux2 = true;
			while (aux2)
			{
				int aux = rand() % 4 + 1;
				switch (aux) {
				case 1:
					if (mapa.getCella(X, Y - 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y - 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 2:
					if (mapa.getCella(X, Y + 1) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X;
						aux3.Y = Y + 1;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 3:
					if (mapa.getCella(X - 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X - 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				case 4:
					if (mapa.getCella(X + 1, Y) == Cella::VACIA)
					{
						Vector aux3;
						aux3.X = X + 1;
						aux3.Y = Y;
						mapa.GenerateCoin(aux3);
						aux2 = false;
					}
					break;
				}
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}

}

void Player::addDinero(int maxDienro) {

	int monyGet = rand() % maxDienro + 1;

	mony += monyGet;

}

void Player::Reed_input(Actions input) {
	if (input == Actions::UP) {
		position.Y--;
		lastMoveInput = Actions::UP;
	}

	if (input == Actions::DOWN) {
		position.Y++;
		lastMoveInput = Actions::DOWN;
	}
	if (input == Actions::LEFT) {
		position.X--;
		lastMoveInput = Actions::LEFT;
	}
	if (input == Actions::RIGHT) {
		position.X++;
		lastMoveInput = Actions::RIGHT;
	}

}

void Player::AtackPeaton(peaton& peatones, Mapa mapa) {

	if (peatones.getCanMove() == false) {
		peatones.DamagePeaton(Damage);
	}
}

void Player::AtackBigSmoke(BigSmoke& BG, Mapa mapa) {

	if (BG.getCanMove() == false) {
		BG.DamageBigSmoke(Damage);
	}
}


void Player::EnterCar(Coches coche, int nCar) {
	for (int i = position.Y - 1; i < position.Y + 1; i++) {
		for (int j = position.X - 1; j < position.X + 1; j++) {
			if (coche.GetPositionCar().Y == i && coche.GetPositionCar().X == j) {
				canEnterCar = true;
				posCoche.X = j;
				posCoche.Y = i;
				saveNCar = nCar;
				return;
			}
		}
	}
}

void Player::ExitCar(Mapa& mapa, std::vector<Coches>& cotxes) {
	bool aux2 = true;
	
	while (aux2)
	{
		int aux = rand() % 4 + 1;
		switch (aux)
		{
		case 1:
			if (mapa.getCella(position.X, position.Y - 1) == Cella::VACIA)
			{
				for (int i = 0; i < cotxes.size(); i++)
				{
					if (i == saveNCar)
					{
						cotxes[saveNCar].setPositionCar(position.X, position.Y);
						mapa.SetCella(position.X, position.Y, Cella::COCHE);
					}
				}
				aux2 = false;
				position.Y = position.Y - 1;
				mapa.SetCella(position.X, position.Y, Cella::PLAYER);
			}
			break;
		case 2:
			if (mapa.getCella(position.X, position.Y + 1) == Cella::VACIA)
			{
				for (int i = 0; i < cotxes.size(); i++)
				{
					if (i == saveNCar)
					{
						cotxes[saveNCar].setPositionCar(position.X, position.Y);
						mapa.SetCella(position.X, position.Y, Cella::COCHE);
					}
				}
				aux2 = false;
				position.Y = position.Y + 1;
				mapa.SetCella(position.X, position.Y, Cella::PLAYER);
			}
			break;
		case 3:
			if (mapa.getCella(position.X + 1, position.Y) == Cella::VACIA)
			{
				for (int i = 0; i < cotxes.size(); i++)
				{
					if (i == saveNCar)
					{
						cotxes[saveNCar].setPositionCar(position.X, position.Y);
						mapa.SetCella(position.X, position.Y, Cella::COCHE);
					}
				}
				aux2 = false;
				position.X = position.X + 1;
				mapa.SetCella(position.X, position.Y, Cella::PLAYER);
			}
			break;
		case 4:
			if (mapa.getCella(position.X - 1, position.Y) == Cella::VACIA)
			{
				for (int i = 0; i < cotxes.size(); i++)
				{
					if (i == saveNCar)
					{
						cotxes[saveNCar].setPositionCar(position.X, position.Y);
						mapa.SetCella(position.X, position.Y, Cella::COCHE);
					}
				}
				aux2 = false;
				position.X = position.X - 1;
				mapa.SetCella(position.X, position.Y, Cella::PLAYER);
			}
			break;
		}
	}
	inCar = false;
}