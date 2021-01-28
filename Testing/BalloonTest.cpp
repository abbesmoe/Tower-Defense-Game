#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Item.h"
#include "Balloon.h"
#include "BlackBalloon.h"
#include "BlueBalloon.h"
#include "RedBalloon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// filename 
const std::wstring red = L"images/red-balloon.png";
const std::wstring blue = L"images/blue-balloon.png";
const std::wstring black = L"images/black-balloon.png";

namespace TestingRed
{
    /** Mock class for testing CItem */
    class CItemMock : public CItem
    {
    public:
        /** Constructor
         * \param aquarium The aquarium this is a member of */
        CItemMock(CGame* game) :
            CItem(game) {}

        /** Draw the item
         * \param graphics The graphics context to draw on */
        virtual void Draw(Gdiplus::Graphics* graphics) {}

    };

    TEST_CLASS(RedTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestRedHitTest)
        {
            // Create an item to test
            CGame game;
            CRedBalloon item(&game);
            
            Assert::AreEqual(5.5, item.GetSpeed(), 0.0001);
            Assert::IsFalse(item.IsPopped(),false);
            Assert::AreEqual(1, item.GetLives());
        }
    };
}

namespace TestingBlue
{
    /** Mock class for testing CItem */
    class CItemMock : public CItem
    {
    public:
        /** Constructor
         * \param aquarium The aquarium this is a member of */
        CItemMock(CGame* game) :
            CItem(game) {}

        /** Draw the item
         * \param graphics The graphics context to draw on */
        virtual void Draw(Gdiplus::Graphics* graphics) {}

    };

    TEST_CLASS(BlueTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestBlueHitTest)
        {
            // Create an item to test
            CGame game;
            CBlueBalloon item(&game);

            Assert::AreEqual(4, item.GetSpeed(), 0.0001);
            Assert::IsFalse(item.IsPopped(), false);
            Assert::AreEqual(2, item.GetLives());
        }
    };
}

namespace TestingBlack
{
    /** Mock class for testing CItem */
    class CItemMock : public CItem
    {
    public:
        /** Constructor
         * \param aquarium The aquarium this is a member of */
        CItemMock(CGame* game) :
            CItem(game) {}

        /** Draw the item
         * \param graphics The graphics context to draw on */
        virtual void Draw(Gdiplus::Graphics* graphics) {}

    };

    TEST_CLASS(BlackTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestBlackHitTest)
        {
            // Create an item to test
            CGame game;
            CBlueBalloon item(&game);

            Assert::AreEqual(8, item.GetSpeed(), 0.0001);
            Assert::IsFalse(item.IsPopped(), false);
            Assert::AreEqual(1, item.GetLives());
        }
    };
}