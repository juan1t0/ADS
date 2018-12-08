#pragma once
#include "SSElement.h"

typedef std::vector<SSElement*> child_array;

class SSBranch :
	public SSElement
{
public:
	child_array children;
	uin quant_child;
	uin total_children_subtree;
	SSBranch();
	~SSBranch();

	void includin(dato&);
};

