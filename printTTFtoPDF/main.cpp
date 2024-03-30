#define _CRT_SECURE_NO_WARNINGS
#include "hpdf.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

// 每行的字符数
const int chars_per_line = 10;
// 每页的行数
const int lines_per_page = 20;
// 字符的横向间距
const int char_spacing = 40;
// 字符的纵向间距
const int line_spacing = 35;

// 检查是否需要新建一页
bool needNewPage(int char_cnt) {
    return char_cnt % (chars_per_line * lines_per_page) == 0;
}

// 创建新的一页并设置页面属性
HPDF_Page createNewPage(HPDF_Doc pdf, HPDF_Font font) {
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
    HPDF_Page_SetFontAndSize(page, font, 30);
    HPDF_Page_BeginText(page);
    return page;
}

int main() {
    setlocale(LC_ALL, "en_US.utf8");

    HPDF_Doc pdf = HPDF_New(nullptr, nullptr);
    if (!pdf) {
        printf("error: cannot create PdfDoc object\n");
        return 1;
    }

    HPDF_UseUTFEncodings(pdf);
    HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);

    const char* font_name = HPDF_LoadTTFontFromFile(pdf, "font\\Arial Unicode MS.ttf", HPDF_TRUE);
    HPDF_Font font = HPDF_GetFont(pdf, font_name, "UTF-8");

    HPDF_Page page = nullptr;
    int char_cnt = 0;
    for (int i = 0; i < 65536; i++) {
        if (needNewPage(char_cnt)) {
            if (page) {
                HPDF_Page_EndText(page);
            }
            page = createNewPage(pdf, font);
        }

        int line = (char_cnt / chars_per_line) % lines_per_page; // 行数
        int col = char_cnt % chars_per_line; // 列数
        HPDF_Page_TextOut(page, 10 + col * char_spacing, 750 - line * line_spacing, " ");

        wchar_t wc = i;
        char utf8[5] = { 0 };
        wctomb(utf8, wc); // 宽字符转换为多字节字符
        HPDF_Page_ShowText(page, utf8);

        char_cnt++;
    }

    if (!needNewPage(char_cnt)) {
        HPDF_Page_EndText(page);
    }

    HPDF_SaveToFile(pdf, "fontdoc.pdf");
    HPDF_Free(pdf);

    return 0;
}