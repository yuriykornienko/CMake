#pragma once

#include <stdint.h>
#include <string>

using Price = double;

struct Candle
{

	Price open;
	Price high;
	Price low;
	Price close;

	Candle() = default;
	Candle(Price open, Price high, Price low, Price close);


	//находится ли цена внутри тела этой свечи
	bool body_contains(const Price& price) const noexcept;

	//находится ли цена внутри тела и теней
	//другими словами, касается ли цена
	//тела или теней свечи
	bool contains(const Price& price) const noexcept;

	//возвращает размер целой свечи, включая тени
	double full_size() const noexcept;

	//возвращает размер тела свечи
	double body_size() const noexcept;

	bool is_green() const noexcept;
	bool is_red() const noexcept;

};
