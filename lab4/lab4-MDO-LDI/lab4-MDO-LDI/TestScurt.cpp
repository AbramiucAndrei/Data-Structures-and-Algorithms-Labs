#include <assert.h>

#include "MDO.h"
#include "IteratorMDO.h"

#include <exception>
#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	MDO dictOrd = MDO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,3);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());
    vector<TValoare> v= dictOrd.cauta(1);
    assert(v.size()==2);
    v= dictOrd.cauta(3);
    assert(v.size()==0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
    	TElem e = it.element();
    	it.urmator();
    }



    IteratorMDO it2 = dictOrd.iterator();
    it2.avanseaza(2);
    assert(it.valid() == 0);
    try {
        it.element();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    dictOrd.adauga(3, 3);
    it2.prim();
    try {
        it2.avanseaza(5);
        assert(false);
    }
    catch(exception&) {
        assert(true);
    }

    it2.prim();
    it2.avanseaza(2);
    assert(it2.element() == TElem(3, 3));
    assert(dictOrd.sterge(3, 3) == true);




    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());


}

