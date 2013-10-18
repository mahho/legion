#include "CButton.h"

CButton::CButton() {
	visible = false;
}
CButton::~CButton() {}

void CButton::setProperties(SPoint pos, int type) {
	switch (type) {
		case button::OK: 
			myPosition = pos;
			myType = button::OK;
			break;
		case button::ORDERS:
			myPosition = pos;
			myType = button::ORDERS;
			break;
	}

}

