#ifndef BUILDER_H
#define BUILDER_H
/*
*	生成器模式
*/
/*
*	实例：一个RTF文档交换格式的阅读器应能将RTF转换为多种正文格式；而且转换的数目是无限的
*         使用生成器模式可以很容易实现增加新的转换模式 同事不改变RTF阅读器
*/

#include <iostream>
using namespace std;

class Text
{

};

class ASCIIText : public Text
{

};

class TeXText : public Text
{

};

class TextWidget : public Text
{

};

class TextConverter
{
public:
	TextConverter()
	{

	}

	virtual ~TextConverter()
	{

	}

public:
	virtual void ConvertCharacter() = 0;
	virtual void ConvertFontChange()
	{

	};
	virtual void ConvertParagraph()
	{

	};
};

class ASCIIConverter : public TextConverter
{
public: 
	ASCIIConverter()
	{
		cout << "create ascii converter" << endl;
		asscii_text_ = new ASCIIText();
	}
	~ASCIIConverter()
	{
		delete asscii_text_;
	}
public:
	void ConvertCharacter()
	{
		cout << "Convert character ..." << endl;
		//修改asscii_text_;
	}

	Text* GetASCIIText()
	{
		return asscii_text_;
	}
private:
	ASCIIText* asscii_text_;
};

class TeXConverter : public TextConverter
{
public:
	TeXConverter()
	{
		cout << "create tex converter " << endl;
		tex_text_ = new TeXText();
	}
	~TeXConverter()
	{
		delete tex_text_;
	}
	virtual void ConvertCharacter()
	{
		cout << "Convert Character ..." << endl;
		//修改TexText;
	}
	virtual void ConvertFontChange()
	{
		cout << "Convert Font Change ..." << endl;
	}
	virtual void ConvertParagraph()
	{
		cout << "Convert Paragraph ..." << endl;
	}
	Text* GetTeXText()
	{
		return tex_text_;
	}
private:
	TeXText* tex_text_;
};

class TextWidgetConverter : public TextConverter
{
public:
	TextWidgetConverter()
	{
		cout << "create TextWidgetConverter " << endl;
		text_widget_ = new TextWidget();
	}
	~TextWidgetConverter()
	{
		delete text_widget_;
	}
	virtual void ConvertCharacter()
	{
		cout << "Convert Character ..." << endl;
	}
	virtual void ConvertFontChange()
	{
		cout << "Convert Font Change ..." << endl;
	}
	virtual void ConvertParagraph()
	{
		cout << "Convert Paragraph ..." << endl;
	}
	Text* GetTextWidget()
	{
		return text_widget_;
	}
private:
	TextWidget* text_widget_;
};

class RTFReader
{
public:
	RTFReader(TextConverter* text_converter)
	{
		text_converter_ = text_converter;
	}
	~RTFReader()
	{

	}
	void ParseRtf(int type = 0)
	{
		if (type == 1)
		{
			text_converter_->ConvertCharacter();
		}
		else
		{
			text_converter_->ConvertCharacter();
			text_converter_->ConvertFontChange();
			text_converter_->ConvertParagraph();
		}
	}

private:
	TextConverter* text_converter_;

};

void TestBuilder()
{
	ASCIIConverter* converter1 = NULL;
	TeXConverter* converter2 = NULL;
	converter1 = new ASCIIConverter();
	converter2 = new TeXConverter();
	RTFReader reader1(converter1);
	RTFReader reader2(converter2);
	reader2.ParseRtf(1);
	reader2.ParseRtf();
	Text* text1 = converter1->GetASCIIText();
	Text* text2 = converter2->GetTeXText();
	delete converter1;
	delete converter2;
}

#endif