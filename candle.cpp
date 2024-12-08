﻿#include "candle.h"

#include <string>
#include <stdexcept>

Candle::Candle(Price open, Price high, Price low, Price close)
	: open(open)
	, high(high)
	, low(low)
	, close(close)
{
}

bool Candle::body_contains(const Price &price) const noexcept
{
	if(is_green())
	{
		const Price &max = close;
		const Price &min = open;
		return price >= min && price <= max;
	}
	else
	{
		const Price &max = open;
		const Price &min = close;
		return price >= min && price <= max;
	}
}

bool Candle::contains(const Price &price) const noexcept
{
	return price >= low && price <= high;
}

double Candle::full_size() const noexcept
{
	return std::abs(low - high);
}

double Candle::body_size() const noexcept
{
	return std::abs(open - close);
}

bool Candle::is_green() const noexcept
{
	return close > open;
}

bool Candle::is_red() const noexcept
{
	return close < open;
}
