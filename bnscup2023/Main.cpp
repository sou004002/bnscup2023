# include <Siv3D.hpp>

void Main()
{
	Vec2 pos = { Scene::Center().x,200 };
	float g = 9.81f;
	float t = 0.0f;
	bool isJump = false;
	while (System::Update())
	{
		ClearPrint();
		const double delta = (Scene::DeltaTime() * 200);
		if (!isJump) {
			t += Scene::DeltaTime();
		}

		Rect field{ 0,500,800,100 };
		Circle player{ pos, 20 };

		// 上下左右キーで移動
		if (KeyLeft.pressed())
		{
			pos.x -= delta;
		}

		if (KeyRight.pressed())
		{
			pos.x += delta;
		}

		// [C] キーが押されたら中央に戻る
		if (KeyC.down())
		{
			pos = Scene::Center();
		}
		float vy = (float)t * g;
		if (player.intersects(field)) {
			t = 0.0f;
			vy = 0.0f;
			isJump = true;
		}
		if (KeySpace.pressed() && isJump) {
			vy -= 100.0f;
			isJump = false;
		}


		pos.y += vy;

		field.draw();
		player.draw(Palette::Skyblue);
		Print << vy;

	}
}
//適当なコメント
//くぁｗせつｊぉｐ；＠：「

//git難しいンゴ～～！

//肉じゃが肉じゃが肉じゃが肉じゃが肉じゃが肉じゃが肉じゃが肉じゃが

//枝豆おいしい


//ふ～ん、fetchじゃんけんぽん
//ソラマメ

//もうconflictしない/Merge原敬之
//くぁｗせｄｒｆｔｇｙふじこｌ
//働きたくないでござる～～～～～
//aaaaa
//バイトの面接落ちました。

//もう眠いかな？
//ぼくのさぎょうです
