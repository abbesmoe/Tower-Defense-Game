#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Bomb.h"
#include "TowerEight.h"
#include "RingTower.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// filenames
const std::wstring filenamebomb = L"images/tower-bomb.png";
const std::wstring filenameeight = L"images/tower8.png";
const std::wstring filenamering = L"images/tower-rings.png";

namespace TestingBomb
{
//	/** Mock class for testing CItem */
//	class CItemMock : public CItem
//	{
//	public:
//		/** Constructor
//		 * \param game The game this is a member of */
//		CItemMock(CGame* game) :
//			CItem(game) {}
//
//		/** Draw the item
//		 * \param graphics The graphics context to draw on */
//		virtual void Draw(Gdiplus::Graphics* graphics) {}
//
//	};
//
//
//	TEST_CLASS(CBombTest)
//	{
//	public:
//
//		TEST_METHOD_INITIALIZE(methodName)
//		{
//			extern wchar_t g_dir[];
//			::SetCurrentDirectory(g_dir);
//		}
//
//		TEST_METHOD(TestCBombConstruct)
//		{
//			// Construct an item to test
//			CGame game;
//			CBomb bomb(&game);
//		}
//
//
//	};
//}
//
//namespace TestingTowerEight
//{
//	/** Mock class for testing CItem */
//	class CItemMock : public CItem
//	{
//	public:
//		/** Constructor
//		 * \param aquarium The aquarium this is a member of */
//		CItemMock(CGame* game) :
//			CItem(game) {}
//
//		/** Draw the item
//		 * \param graphics The graphics context to draw on */
//		virtual void Draw(Gdiplus::Graphics* graphics) {}
//
//	};
//
//
//	TEST_CLASS(CTowerEightTest)
//	{
//	public:
//
//		TEST_METHOD_INITIALIZE(methodName)
//		{
//			extern wchar_t g_dir[];
//			::SetCurrentDirectory(g_dir);
//		}
//
//		TEST_METHOD(TestCBombConstruct)
//		{
//			// Construct an item to test
//			CGame game;
//			CTowerEight eight(&game);
//		}
//
//
//	};
//}
//
//namespace TestingTowerRings
//{
//	/** Mock class for testing CItem */
//	class CItemMock : public CItem
//	{
//	public:
//		/** Constructor
//		 * \param aquarium The aquarium this is a member of */
//		CItemMock(CGame* game) :
//			CItem(game) {}
//
//		/** Draw the item
//		 * \param graphics The graphics context to draw on */
//		virtual void Draw(Gdiplus::Graphics* graphics) {}
//
//	};
//
//
//	TEST_CLASS(CTowerRingsTest)
//	{
//	public:
//
//		TEST_METHOD_INITIALIZE(methodName)
//		{
//			extern wchar_t g_dir[];
//			::SetCurrentDirectory(g_dir);
//		}
//
//		TEST_METHOD(TestCBombConstruct)
//		{
//			// Construct an item to test
//			CGame game;
//			CRingTower ring(&game);
//		}
//
//
//	};
}