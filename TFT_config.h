
///////////////////////////////////////////////////////////
/*           Support file for ESP32 IDF use              */
/*              See library docs folder                  */
/*                                                       */
/*              DO NOT EDIT THIS FILE                    */
/*                                                       */
///////////////////////////////////////////////////////////

/**
 * @file   TFT_config.h
 * @author Ricard Bitriá Ribes (https://github.com/dracir9)
 * Created Date: 22-01-2022
 * -----
 * Last Modified: 25-02-2023
 * Modified By: Ricard Bitriá Ribes
 * -----
 * @copyright (c) 2022 Ricard Bitriá Ribes
 */

#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

#include "sdkconfig.h"

/***************************************************************************************
**                         TFT_eSPI Configuration defines
***************************************************************************************/
// Override defaults
#define USER_SETUP_LOADED

/***************************************************************************************
**                         Section 1: Load TFT driver
***************************************************************************************/
#if defined (CONFIG_TFT_ILI9341_DRIVER)
    #define ILI9341_DRIVER
#elif defined (CONFIG_TFT_ILI9341_2_DRIVER)
    #define ILI9341_2_DRIVER
#elif defined (CONFIG_TFT_ST7735_DRIVER)
    #define ST7735_DRIVER
#elif defined (CONFIG_TFT_ILI9163_DRIVER)
    #define ILI9163_DRIVER
#elif defined (CONFIG_TFT_S6D02A1_DRIVER)
    #define S6D02A1_DRIVER
#elif defined (CONFIG_TFT_HX8357D_DRIVER)
    #define HX8357D_DRIVER
#elif defined (CONFIG_TFT_ILI9481_DRIVER)
    #define ILI9481_DRIVER
#elif defined (CONFIG_TFT_ILI9486_DRIVER)
    #define ILI9486_DRIVER
#elif defined (CONFIG_TFT_ILI9488_DRIVER)
    #define ILI9488_DRIVER
#elif defined (CONFIG_TFT_ST7789_DRIVER)
    #define ST7789_DRIVER
#elif defined (CONFIG_TFT_ST7789_2_DRIVER)
    #define ST7789_2_DRIVER
#elif defined (CONFIG_TFT_R61581_DRIVER)
    #define R61581_DRIVER
#elif defined (CONFIG_TFT_RM68140_DRIVER)
    #define RM68140_DRIVER
#elif defined (CONFIG_TFT_ST7796_DRIVER)
    #define ST7796_DRIVER
#elif defined (CONFIG_TFT_SSD1351_DRIVER)
    #define SSD1351_DRIVER
#elif defined (CONFIG_TFT_SSD1681_DRIVER)
    #define SSD1681_DRIVER
#elif defined (CONFIG_TFT_SSD1963_480_DRIVER)
    #define SSD1963_480_DRIVER
#elif defined (CONFIG_TFT_SSD1963_800_DRIVER)
    #define SSD1963_800_DRIVER
#elif defined (CONFIG_TFT_SSD1963_800ALT_DRIVER)
    #define SSD1963_800ALT_DRIVER
#elif defined (CONFIG_TFT_ILI9225_DRIVER)
    #define ILI9225_DRIVER
#elif defined (CONFIG_TFT_GC9A01_DRIVER)
    #define GC9A01_DRIVER
#endif

#ifdef CONFIG_TFT_RGB_ORDER
    #define TFT_RGB_ORDER TFT_RGB
#endif

#ifdef CONFIG_TFT_BGR_ORDER
    #define TFT_RGB_ORDER TFT_BGR
#endif

#ifdef CONFIG_TFT_M5STACK
    #define M5STACK
#endif

#ifdef CONFIG_TFT_WIDTH
    #define TFT_WIDTH   CONFIG_TFT_WIDTH
#endif

#ifdef CONFIG_TFT_HEIGHT
    #define TFT_HEIGHT   CONFIG_TFT_HEIGHT
#endif

#if defined (CONFIG_TFT_ST7735_INITB)
    #define ST7735_INITB
#elif defined (CONFIG_TFT_ST7735_GREENTAB)
    #define ST7735_GREENTAB
#elif defined (CONFIG_TFT_ST7735_GREENTAB2)
    #define ST7735_GREENTAB2
#elif defined (CONFIG_TFT_ST7735_GREENTAB3)
    #define ST7735_GREENTAB3
#elif defined (CONFIG_TFT_ST7735_GREENTAB128)
    #define ST7735_GREENTAB128
#elif defined (CONFIG_TFT_ST7735_GREENTAB160x80)
    #define ST7735_GREENTAB160x80
#elif defined (CONFIG_TFT_ST7735_REDTAB)
    #define ST7735_REDTAB
#elif defined (CONFIG_TFT_ST7735_BLACKTAB)
    #define ST7735_BLACKTAB
#elif defined (CONFIG_TFT_ST7735_REDTAB160x80)
    #define ST7735_REDTAB160x80
#endif

#if defined (CONFIG_TFT_INVERSION_ON)
    #define TFT_INVERSION_ON
#elif defined (CONFIG_TFT_INVERSION_OFF)
    #define TFT_INVERSION_OFF
#endif

/***************************************************************************************
**                         Section 2: General Pin configuration
***************************************************************************************/
// General pins
#if CONFIG_TFT_CS == -1
    #error "Invalid Chip Select pin. Check TFT_eSPI configuration"
#else
    #define TFT_CS          CONFIG_TFT_CS
#endif

#if CONFIG_TFT_DC == -1
    #error "Invalid Data/Command pin. Check TFT_eSPI configuration"
#else
    #define TFT_DC          CONFIG_TFT_DC
#endif

#if CONFIG_TFT_RST == -1
    #error "Invalid Reset pin. Check TFT_eSPI configuration"
#else
    #define TFT_RST         CONFIG_TFT_RST
#endif

// Backlight config
#ifdef CONFIG_ENABLE_BL
    #if CONFIG_TFT_BL == -1
        #error "Invalid backlight control pin. Check TFT_eSPI configuration"
    #else
        #define TFT_BL      CONFIG_TFT_BL
    #endif

    #define TFT_BACKLIGHT_ON CONFIG_TFT_BACKLIGHT_ON
#endif


/***************************************************************************************
**                         Section 3: Data bus Pin configuration
***************************************************************************************/

// 8 BIT PARALLEL BUS
#ifdef CONFIG_TFT_PARALLEL_8_BIT

    #define TFT_PARALLEL_8_BIT

    #if CONFIG_TFT_D0 == -1
        #error "Invalid Data 0 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D0      CONFIG_TFT_D0
    #endif

    #if CONFIG_TFT_D1 == -1
        #error "Invalid Data 1 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D1      CONFIG_TFT_D1
    #endif

    #if CONFIG_TFT_D2 == -1
        #error "Invalid Data 2 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D2      CONFIG_TFT_D2
    #endif

    #if CONFIG_TFT_D3 == -1
        #error "Invalid Data 3 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D3      CONFIG_TFT_D3
    #endif

    #if CONFIG_TFT_D4 == -1
        #error "Invalid Data 4 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D4      CONFIG_TFT_D4
    #endif

    #if CONFIG_TFT_D5 == -1
        #error "Invalid Data 5 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D5      CONFIG_TFT_D5
    #endif

    #if CONFIG_TFT_D6 == -1
        #error "Invalid Data 6 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D6      CONFIG_TFT_D6
    #endif

    #if CONFIG_TFT_D7 == -1
        #error "Invalid Data 7 pin. Check TFT_eSPI configuration"
    #else
        #define TFT_D7      CONFIG_TFT_D7
    #endif
    
    #if CONFIG_TFT_WR == -1
        #error "Invalid Write strobe pin. Check TFT_eSPI configuration"
    #else
        #define TFT_WR      CONFIG_TFT_WR
    #endif

    #if CONFIG_TFT_RD == -1
        #error "Invalid Read strobe pin. Check TFT_eSPI configuration"
    #else
        #define TFT_RD      CONFIG_TFT_RD
    #endif

// SPI BUS
#else
    #if CONFIG_TFT_HSPI_PORT
        #define USE_HSPI_PORT
    #endif

    #if CONFIG_TFT_MISO != -1
        #define TFT_MISO      CONFIG_TFT_MISO
    #endif

    #if CONFIG_TFT_MOSI == -1
        #error "Invalid MOSI pin. Check TFT_eSPI configuration"
    #else
        #define TFT_MOSI      CONFIG_TFT_MOSI
    #endif

    #if CONFIG_TFT_SCLK == -1
        #error "Invalid Clock pin. Check TFT_eSPI configuration"
    #else
        #define TFT_SCLK      CONFIG_TFT_SCLK
    #endif

    #define SPI_FREQUENCY   CONFIG_TFT_SPI_FREQUENCY

    #if CONFIG_TFT_SPI_READ_FREQ != -1
        #define SPI_READ_FREQUENCY CONFIG_TFT_SPI_READ_FREQ
    #endif
    
    #ifdef CONFIG_TFT_SDA_READ
        #define TFT_SDA_READ
    #endif
#endif


/***************************************************************************************
**                         Section 4: Setup Fonts
***************************************************************************************/

#ifdef CONFIG_TFT_LOAD_GLCD
    #define LOAD_GLCD       // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#endif

#ifdef CONFIG_TFT_LOAD_FONT2
    #define LOAD_FONT2      // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#endif

#ifdef CONFIG_TFT_LOAD_FONT4
    #define LOAD_FONT4      // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#endif

#ifdef CONFIG_TFT_LOAD_FONT6
    #define LOAD_FONT6      // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#endif

#ifdef CONFIG_TFT_LOAD_FONT7
    #define LOAD_FONT7      // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:.
#endif

#ifdef CONFIG_TFT_LOAD_FONT8
    #define LOAD_FONT8      // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
#endif

#ifdef CONFIG_TFT_LOAD_GFXFF
    #define LOAD_GFXFF      // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts
#endif

#if CONFIG_TFT_SMOOTH_FONT
    #define SMOOTH_FONT
#endif

/***************************************************************************************
**                         Section 5: Touchscreen configuration
***************************************************************************************/

#ifdef CONFIG_ENABLE_TOUCH
    #if CONFIG_TOUCH_CS == -1
        #error "Invalid Touch Chip Select pin. Check TFT_eSPI configuration"
    #else
        #define TOUCH_CS            CONFIG_TOUCH_CS
    #endif

    #define SPI_TOUCH_FREQUENCY CONFIG_SPI_TOUCH_FREQUENCY
#endif

/***************************************************************************************
**                         Section 6: Others
***************************************************************************************/

#ifdef CONFIG_DISABLE_WARNINGS
    #define DISABLE_ALL_LIBRARY_WARNINGS
#endif

#endif // TFT_CONFIG_H
