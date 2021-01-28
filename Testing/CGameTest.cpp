#include "pch.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Tile.h"
#include "Item.h"
#include <string>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCGameConstruct)
		{
			CGame Game;
		}

		TEST_METHOD(TestCGameAddTile)
		{
			CGame Game;
			std::shared_ptr<CTile> tile;
			Assert::IsTrue(Game.GetItem().size() == 0);
			Game.AddItem(tile);
			Game.GetItem();
			Assert::IsTrue(Game.GetItem().size() == 1);
		}

		TEST_METHOD(TestCGameAddItem)
		{
			CGame Game;
			std::shared_ptr<CItem> item;
			Assert::IsTrue(Game.GetItem().size() == 0);
			Game.AddItem(item);
			Assert::IsTrue(Game.GetItem().size() == 1);
		}
	};
}