#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// filename 
const std::wstring filename = L"images/tower8.png";

namespace Testing
{
    /** Mock class for testing CItem */
    //class CItemMock : public CItem
    //{
    //public:
    //    /** Constructor
    //     * \param aquarium The aquarium this is a member of */
    //    CItemMock(CGame* game) :
    //        CItem(game) {}

    //    /** Draw the item
    //     * \param graphics The graphics context to draw on */
    //    virtual void Draw(Gdiplus::Graphics* graphics) {}

    //};

    //TEST_CLASS(CItemTest)
    //{
    //public:
    //    TEST_METHOD_INITIALIZE(methodName)
    //    {
    //        extern wchar_t g_dir[];
    //        ::SetCurrentDirectory(g_dir);
    //    }

    //    TEST_METHOD(TestCItemConstruct)
    //    {
    //        CGame game;
    //        CItemMock item(&game);
    //    }

    //    TEST_METHOD(TestCItemGettersSetters)
    //    {
    //        // Construct an item to test
    //        CGame game;
    //        CItemMock item(&game);

    //        // Test initial values
    //        Assert::AreEqual(0, item.GetX(), 0);
    //        Assert::AreEqual(0, item.GetY(), 0);

    //        // Test SetLocation, GetX, and GetY
    //        item.SetLocation(10.5, 17.2);
    //        Assert::AreEqual(10.5, item.GetX(), 0.0001);
    //        Assert::AreEqual(17.2, item.GetY(), 0.0001);

    //        Assert::AreNotEqual(0, item.GetX(), 0.0001);
    //        Assert::AreNotEqual(0, item.GetY(), 0.0001);

    //        // Test a second with with different values
    //        item.SetLocation(-72, -107);
    //        Assert::AreEqual(-72, item.GetX(), 0.0001);
    //        Assert::AreEqual(-107, item.GetY(), 0.0001);

    //        Assert::AreNotEqual(0, item.GetX(), 0.0001);
    //        Assert::AreNotEqual(0, item.GetY(), 0.0001);
    //    }

    //    TEST_METHOD(TestCItemHitTest)
    //    {
    //        // Create an item to test
    //        CGame game;
    //        CItemMock item(&game);

    //        // Give it a location
    //        // Always make the numbers different, in case they are mixed up
    //        item.SetLocation(100, 200);

    //        // Center of the item should be a true
    //        Assert::IsTrue(item.HitTest(100, 200));

    //        // Left of the item
    //        Assert::IsFalse(item.HitTest(10, 200));

    //        // Right of the item
    //        Assert::IsFalse(item.HitTest(200, 200));

    //        // Above the item
    //        Assert::IsFalse(item.HitTest(100, 0));

    //        // Below the item
    //        Assert::IsFalse(item.HitTest(100, 300));

    //        // Of transparent pixel
    //        Assert::IsFalse(item.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
    //    }

    //    TEST_METHOD(TestCItemMoveTest)
    //    {
    //        // Create an item to test
    //        CGame game;
    //        CItemMock item(&game);

    //        // Give it a location
    //        // Always make the numbers different, in case they are mixed up
    //        item.SetLocation(100, 200);

    //        // Center of the item should be a true
    //        Assert::IsTrue(item.HitTest(100, 200));

    //        // Move up and move right for 5 pixels
    //        item.Move(5, 5);
    //        Assert::IsTrue(item.HitTest(105, 205));

    //        // Move down and move left for 5 pixels
    //        item.Move(-5, -5);
    //        Assert::IsTrue(item.HitTest(100, 200));

    //    TEST_METHOD(TestCItemDistance)
    //    {
    //        // Create an aquarium and two items
    //        CGame game;
    //        std::shared_ptr<CItemMock> item1 = std::make_shared<CItemMock>(&game);
    //        std::shared_ptr<CItemMock> item2 = std::make_shared<CItemMock>(&game);

    //        item1->SetLocation(10.5, 17.2);
    //        item2->SetLocation(53.1, 107.8);

    //        Assert::AreEqual(100.1155, item1->Distance(item2), 0.0001);
    //    }
    //};
}