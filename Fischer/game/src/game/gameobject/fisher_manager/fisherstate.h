#pragma once

enum class FISHER_LEVEL
{
	LOW,
	MIDDLE,
	HIGH,
	HIGHEST
};

enum class FISHER_STATE
{
	RELUX,		// ƒŠƒ‰ƒbƒNƒXó‘Ô
	CAUTION,	// ’Ž‹ó‘Ô
};

enum class FISHER_MOVE
{
	WAIT,		// ’Þ‚èŽ…‚ð‚‚ç‚µ‚Ä‘Ò‚Á‚Ä‚¢‚éó‘Ô
	FISHING,	// ŠÆ‚ðU‚èã‚°‚Ä‚¢‚éó‘Ô
	ATTACH		// ‰a‚ð‚Â‚¯‚Ä‚¢‚éó‘Ô
};