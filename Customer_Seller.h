#ifndef __CUSTOMER_SELLER_H
#define __CUSTOMER_SELLER_H

#include "Seller.h"

class Customer_Seller : public Customer, public Seller
{

	public:
		Customer_Seller(const Customer& c,const Seller& s);
		Customer_Seller(const Customer_Seller&);
		Customer_Seller(Customer&& c, Seller&& s);
		virtual ~Customer_Seller();
		void toOs(ostream& os) const;
			
};

#endif