#include "terminal_lib.h"

#include <stddef.h>
#include <stdint.h>

#include "boot_lib.h"

static uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
  return fg | bg << 4;
}

static uint16_t vga_entry(unsigned char uc, uint8_t color)
{
  return (uint16_t)uc | (uint16_t)color << 8;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static volatile uint16_t* terminal_buffer;

void terminal_initialize(void)
{
  terminal_row = VGA_HEIGHT - 1;
  terminal_column = 0;
  terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
  terminal_buffer = (volatile uint16_t*)0xB8000;
  for (size_t y = 0; y < VGA_HEIGHT; y++)
  {
    for (size_t x = 0; x < VGA_WIDTH; x++)
    {
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[index] = vga_entry(' ', terminal_color);
    }
  }
}

void terminal_setcolor(uint8_t color)
{
  terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = vga_entry(c, color);
}

void terminal_scroll(void)
{
  size_t most_lines = VGA_WIDTH * VGA_HEIGHT - VGA_WIDTH;
  boot_memcpy(terminal_buffer, terminal_buffer + VGA_WIDTH,
              most_lines * sizeof(uint16_t));
  for (size_t i = 0; i < VGA_WIDTH; ++i)
  {
    terminal_putentryat(' ', terminal_color, i, VGA_HEIGHT - 1);
  }
}

void terminal_putchar(char c)
{
  if (c == '\n' || terminal_column++ == VGA_WIDTH)
  {
    terminal_scroll();
    terminal_column = 0;
  }
  else
  {
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
  }
}

void terminal_write(const char* data, size_t size)
{
  for (size_t i = 0; i < size; i++) terminal_putchar(data[i]);
}

void terminal_writestring(const char* data)
{
  terminal_write(data, boot_strlen(data));
}

void terminal_writesize(size_t n)
{
  char buff[22];
  for (size_t i = 0; i < 21; ++i)
  {
    buff[i] = ' ';
  }
  buff[20] = '\n';
  buff[21] = '\0';
  size_t_to_str(n, buff, 20);
  terminal_writestring(buff);
}