#pragma once
#include "IToken.h"
#include "rapidxml.hpp"

#include <string>
#include <unordered_map>

class CardDAO
{
public:
	using GemType = IToken::Type;
	using RequestMap = std::unordered_map<GemType, uint16_t>;

	enum class Type
	{
		Noble,
		ExpansionL1,
		ExpansionL2,
		ExpansionL3
	};

	struct Noble
	{
		std::string name;
		uint16_t prestige = 0;
		RequestMap request;
	};

	struct Expansion
	{
		GemType reward = GemType::GreenEmerald;
		uint16_t prestige = 0;
		RequestMap request;
	};

	using NobleMap = std::unordered_map<uint16_t, Noble>;
	using ExpansionMap = std::unordered_map<uint16_t, Expansion>;

public:
	// Constr. = initializes database
	CardDAO();

	// Manipulators
	template <class T>
	static T GetCard(Type type, uint16_t id);

private:
	// Database initializers
	static void InitializeDatabase();
	static void InitializeSpecificData(Type type, rapidxml::xml_node<>* mainRoot);

private:
	static inline bool s_isInitialized = false;
	static const inline std::string s_databasePath = "../external/Cards Database/CardsDatabase.xml";
	static inline NobleMap s_nobleCards;
	static inline ExpansionMap s_expansionL1Cards;
	static inline ExpansionMap s_expansionL2Cards;
	static inline ExpansionMap s_expansionL3Cards;
};

