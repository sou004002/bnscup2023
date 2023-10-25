# include "Mousecursor.cpp"
void Main()
{
	Mousecursor cursor(200, 300);
	while (System::Update())//どう？
	{
		Line{ 300, 200, 300, 600 }.draw(3, Palette::White);
		Line{ 700, 200, 700, 600 }.draw(3, Palette::White);
		Line{ 300, 600, 700, 600 }.draw(3, Palette::White);
		if (SimpleGUI::Button(U"エサを与える", Vec2{ 30, 400 })) {
			cursor.texture = cursor.otete;
			cursor.esa = true;
			cursor.gomi = false;
		}
		if (SimpleGUI::Button(U"ゴミを片付ける", Vec2{ 30, 450 })) {
			cursor.texture = cursor.ami;
			cursor.esa = false;
			cursor.gomi = true;
		}
		ClearPrint();
		cursor.move();
		cursor.draw();
	}
}
