#include "..\headers\Entry.h"


// definition of constructor
Entry::Entry() : sno{ 0 }, mo{ 0.0 }, totaltime{ 0.0 }, totalpay{ 0.0 }, netpay{ 0.0 }, notes{ "-----" }
{
}


// definition of reset function
void Entry::reset()
{
	sno = 0;
	in.reset();
	out.reset();
	mo = 0.0;
	totaltime = 0.0;
	totalpay = 0.0;
	netpay = 0.0;
	notes = "-----";
}

//definition of construct function to construct entry object out of _input object

void Entry::construct(Input& i)
{
	in.construct(i.getiday(), i.getimonth(), i.getiyear(), i.getinhours(), i.getinmins(), i.getinap());
	
	out.construct(i.getoday(), i.getomonth(), i.getoyear(), i.getouthours(), i.getoutmins(), i.getoutap());
	
	mo = i.getmo();
	notes = i.getnotes();
}



bool Entry::check_entry_validity()
{
	if (sno > 0 && in.check_DateTime_validity() && out.check_DateTime_validity())
	{
		if (in.get_Date("day") <= out.get_Date("day") && in.get_Date("month") == out.get_Date("month")
			&& in.get_Date("year") == out.get_Date("year"))
		{
			if (in.get_Date("day") == out.get_Date("day"))
			{
				if (in.get_hh("in") < out.get_hh("out"))
				{
					std::cout << "Entry is valid!" << std::endl;
					return true;
				}
				else
				{
					std::cout << "Entry is Invalid!!!" << std::endl;
					return false;
				}
			}
			else
			{
				std::cout << "Entry is valid!" << std::endl;
				return true;
			}
		}
		else
		{
			std::cout << "Entry is Invalid!!!" << std::endl;
			return false;
		}

		
	}
	else
	{
		std::cout << "INVALID ENTRY ENTERED!!!" << std::endl;
		return false;
	}
}





void Entry::display()
{
	std::cout << sno << ".";
	std::cout << " | ";
	in.display();
	std::cout << " | ";
	out.display();
	std::cout << " | " << mo << " | " << totaltime << " | " << totalpay << " | " << netpay << " | " << "'" << notes << "'" << std::endl;
}



void Entry::write_text(std::ofstream& o) const
{
	o << sno << "*";
	o << " | ";
	in.write_text(o);
	o << " | ";
	out.write_text(o);
	o << " | ";
	o << mo;
	o << " | ";
	o << totaltime;
	o << " | ";
	o << totalpay;
	o << " | ";
	o << netpay;
	o << " | ";
	o << notes;
}


void Entry::write_binary(std::ofstream& o) const
{
	o.write(reinterpret_cast<const char*>(&sno), sizeof(sno));
	in.write_binary(o);
	out.write_binary(o);
	o.write(reinterpret_cast<const char*>(&mo), sizeof(mo));
	o.write(reinterpret_cast<const char*>(&totaltime), sizeof(totaltime));
	o.write(reinterpret_cast<const char*>(&totalpay), sizeof(totalpay));
	o.write(reinterpret_cast<const char*>(&netpay), sizeof(netpay));
	size_t size = notes.size();
	o.write(reinterpret_cast<const char*>(&size), sizeof(size));
	o.write(notes.c_str(), size);
}


void Entry::read_text(std::string line)
{
	std::stringstream tokens(line);

	int t_sno = 0, t_inday = 0, t_inmonth = 0, t_inyear = 0, t_inhour = 0, t_inmin = 0, t_outday = 0, t_outmonth=0,
		t_outyear = 0, t_outhour = 0, t_outmin = 0;
	char t_inap = 'n', t_outap = 'n';
	double t_mo = 0.0, t_totaltime = 0.0, t_totalpay = 0.0, t_netpay = 0.0;
	std::string t_notes;

	tokens >> t_sno >> t_inday >> t_inmonth >> t_inyear >> t_inhour >> t_inmin >> t_inap >> 
		t_outday >> t_outmonth >> t_outyear >> t_outhour >> t_outmin >> t_outap >>
		t_mo >> t_totaltime >> t_totalpay >> t_netpay >> t_notes;

	sno = t_sno;
	in.construct( t_inday, t_inmonth, t_inyear, t_inhour, t_inmin, t_inap );
	out.construct( t_outday, t_outmonth, t_outyear, t_outhour, t_outmin, t_outap );
	mo = t_mo;
	totaltime = t_totaltime;
	totalpay = t_totalpay;
	netpay = t_netpay;
	notes = t_notes;
}



void Entry::read_binary(std::ifstream& i)
{

	i.read(reinterpret_cast<char*>(&sno), sizeof(sno));		
	in.read_binary(i);	
	out.read_binary(i);	
	i.read(reinterpret_cast<char*>(&mo), sizeof(mo));	
	i.read(reinterpret_cast<char*>(&totaltime), sizeof(totaltime));	
	i.read(reinterpret_cast<char*>(&totalpay), sizeof(totalpay));	
	i.read(reinterpret_cast<char*>(&netpay), sizeof(netpay));		
	size_t size;
	if (i.read(reinterpret_cast<char*>(&size), sizeof(size)))
	{
		notes.resize(size);
		i.read(&notes[0], size);
	}
}


void Entry::set_sno(int count)
{
	sno = count;
}


int Entry::get_sno()
{
	return sno;
}


void Entry::mod_sno(const char* mod_type)
{
	if (mod_type == "insert")
		++sno;
	else if (mod_type == "delete")
		--sno;
	else
		std::cout << "UNEXPECTED BEHAVIOUR AT FUNCTION 'void Entry::mod_sno(const char* mod-type)` !!!" << std::endl;
}


int Entry::get_Date(const char* type)
{
	int value{};

	if (type == "day")
		value=out.get_Date("day");
	else if (type == "month")
		value=out.get_Date("month");
	else if (type == "year")
		value=out.get_Date("year");
	else
		std::cout << "Something went wrong while loading date from RECORDS ON THE HARD DRIVE!!!" << std::endl;

	return value;
}

bool operator==(const Entry& e1, const Entry& e2)
{
	if (e1.sno == e2.sno && e1.in == e2.in && e1.out == e2.out && e1.mo == e2.mo
		&& e1.totaltime == e2.totaltime && e1.totalpay == e2.totalpay && e1.netpay == e2.netpay && e1.notes == e2.notes)
		return true;
	else
		return false;
}



void Entry::calculate()
{
	


}


double Entry::hours_elapsed() const
{
	double value{};
	int days{ (out.get_Date("day") - in.get_Date("in")) };
	
	if (days == 0)
	{
		value = out.get_hh("out") - in.get_hh("in");
	}
	else
	{
		value = (static_cast<double>(24.00 * days)) + (24.00 - in.get_hh("in")) + out.get_hh("out");
	}

	return value;
}