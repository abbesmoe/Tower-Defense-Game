#include "pch.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Tile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTileTest)
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

	};
    /**
    *  CTile mock derived object
    */
    class CTileMock : public CTile
    {
    public:
        /**  Constructor
         * \param Game Game this tile is a member of */
        CTileMock(CGame* Game) : CTile(Game)
        {
        }

        ///  Default constructor (disabled)
        CTileMock() = delete;

        ///  Copy constructor (disabled)
        CTileMock(const CTileMock&) = delete;

        ~CTileMock() {}
    };


    TEST_CLASS(CTileTestTwo)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestConstructor)
        {
            CGame Game;
            CTileMock tile(&Game);
        }

        TEST_METHOD(TestCItemSetImage)
        {
            CGame Game;
            CTileMock tile(&Game);

            tile.SetImage(L"image.png");
            
            Assert::IsTrue(tile.GetFile() == L"image.png", L"GetFile test");

        }

    };
}