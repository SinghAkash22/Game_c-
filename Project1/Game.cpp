#include "Game.h"
Game::Game()
{
	mywindo = nullptr;
	isruninng = true;
	bolpos.x = 500;
	bolpos.y = 300;
	padlpos.x = 0;
	padlpos.y = 300;
	mtickcou = 0;
}

bool Game::initialise()
{
	int stlsta = SDL_Init(SDL_INIT_VIDEO);
	if (stlsta != 0)
	{
		SDL_Log("viodo  not work");
		return false;
	}
	mywindo = SDL_CreateWindow(
		"my window game",
		50,
		50,
		1000,
		600,
		0
	);
	if (!mywindo)
	{
		SDL_Log("not windo");
		return false;
	}
	mrender = SDL_CreateRenderer(
		mywindo,
		-1,
		SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC
	);
	if (!mrender)
	{
		SDL_Log("not render");
		return false;
	}
	bolvelo.x = -200.0f;
	bolvelo.y = 230.0f;
	return true;
}
void Game::stopgame()
{
	SDL_DestroyRenderer(mrender);
	SDL_DestroyWindow(mywindo);
	SDL_Quit();
}
void Game::gameloop()
{
	while (isruninng)
	{
		getinput();
		update();
		givout();
	}
}
void Game::getinput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		paddldir = 0;
		switch (event.type)
		{
		case SDL_QUIT:
			isruninng = false;
		}
		const Uint8* state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_E])
		{
			isruninng = false;
		}
		if (state[SDL_SCANCODE_W])
		{
			paddldir = -1;
		}
		if (state[SDL_SCANCODE_S])
		{
			paddldir = 1;
		}
	}
}
void Game::update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mtickcou + 16))
		;
	float deltime = (SDL_GetTicks() - mtickcou) / 1000.0f;
	if (deltime > 0.05f)
	{
		deltime = 0.05f;
	}
	mtickcou = SDL_GetTicks();
	if (paddldir != 0)
	{
		padlpos.y += paddldir * deltime * 300.0f;
		if (padlpos.y < (80 / 2.0f + thisness))
		{
			padlpos.y = 80 / 2.0f + thisness;
		}
		else if(padlpos.y>(600.0f-80/2.0f-thisness)) 
		{
			padlpos.y=600.0f-80/2.0f-thisness;
		}
	}
	if (bolpos.y <= thisness && bolvelo.y < 0.0f)
	{
		bolvelo.y *= -1.0f;
	}
	if (bolpos.y >= (600.0f - thisness )&& bolvelo.y > 0.0f)
	{
		bolvelo.y*=-1.0f;
	}
	if (bolpos.x >= (1000.0f - thisness) && bolvelo.x > 0.0f)
	{
		bolvelo.x*=-1.0f;
	}
	bolpos.x += bolvelo.x * deltime;
	bolpos.y += bolvelo.y * deltime;
	float diff = padlpos.y - bolpos.y;
	diff = (diff > 0.0f) ? diff : -diff;
	if (diff <= 80 / 2.0f && bolpos.x <= 25.0f&&bolpos.x>=20.0f && bolvelo.x < 0.0f)
	{
		bolvelo.x *= -1.0f;
	}
	else if(bolpos.x<=0.0f)
	{
		isruninng = false;
	}
}
void Game::givout()
{
	SDL_SetRenderDrawColor(
		mrender,
		0,
		30,
		250,
		100
	);
	SDL_RenderClear(mrender);
	SDL_SetRenderDrawColor(
		mrender,
		111,
		29,
		0,
		89
	);
	SDL_Rect diwar{
		0,
		10,
		1000,
		thisness
	};
	SDL_RenderFillRect(mrender,&diwar);
	SDL_SetRenderDrawColor(
		mrender,
		233,
		0,
		34,
		0
	);
	SDL_Rect bol{
		static_cast<int>(bolpos.x - thisness / 2),
		static_cast<int>(bolpos.y - thisness / 2),
		thisness,
		thisness
	};
	SDL_RenderFillRect(mrender, &bol);
	SDL_SetRenderDrawColor(
		mrender,
		222,
		200,
		0,
		150
		);
	SDL_Rect paddle{
		0,
		static_cast<int>(padlpos.y - thisness / 2),
		thisness,
		80
	};
	SDL_RenderFillRect(mrender, &paddle);
	SDL_RenderPresent(mrender);
}