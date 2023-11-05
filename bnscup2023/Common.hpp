#pragma once
#include <Siv3D.hpp>

enum class State
{
	Title,
	Game,
};

struct GameData //シーン間で共有するデータ
{

};

using App = SceneManager<State, GameData>;
