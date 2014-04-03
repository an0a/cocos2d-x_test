#pragma once



class CConsole
{
	public:
		enum EColorType
		{
			COLOR_DEBUG,
			COLOR_WARNING,
			COLOR_INFO,
			COLOR_ERROR,
			COLOR_MAX_NUM,
		};

	public:
		void Init();
		bool Create( int posX, int posY );
		void Destroy();

		void SetColor( UINT colorType );
		void SetConsolePos( int x, int y );
		void WriteText( const char* szText, size_t textLen );

	private:
		HANDLE m_hConsole;
};




