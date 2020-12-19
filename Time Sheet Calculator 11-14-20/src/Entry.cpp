#include "..\headers\Entry.h"


// definition of constructor
Entry::Entry() : sno{ 0 }, mo{ 0.0 }, totaltime{ 0.0 }, totalpay{ 0.0 }, netpay{ 0.0 }, notes{ "-----" }
{
}


// definition of reset function
void Entry::reset()
{
	sno = 0;
	d.reset();
	intime.reset();
	outtime.reset();
	mo = 0.0;
	totaltime = 0.0;
	totalpay = 0.0;
	netpay = 0.0;
	notes = "-----";
}

//definition of construct function to construct entry object out of _input object

void Entry::construct(Input& i)
{
	d.construct(i.getmonth(), i.getday());
	intime.construct(i.getinhours(), i.getinmins(), i.getinap());
	outtime.construct(i.getouthours(), i.getoutmins(), i.getoutap());
	mo = i.getmo();
	notes = i.getnotes();
}



bool Entry::check_entry_validity()
{
	if (sno == 0)
	{
		std::cout << "Entry is invalid!!!" << std::endl;
		return false;
	}
	if (sno < 0)
	{
		std::cout << "Entry is invalid!!!" << std::endl;
		return false;
	}
	if (!d.check_date_validity())
	{
		std::cout << "Entry is invalid!!!" << std::endl;
		return false;
	}
	if (!intime.check_time_validity())
	{
		std::cout << "Entry is invalid!!!" << std::endl;
		return false;
	}
	if (!outtime.check_time_validity())
	{
		std::cout << "Entry is invalid!!!" << std::endl;
		return false;
	}
	std::cout << "\nEntry is Valid!" << std::endl;
	return true;
}





void Entry::display()
{
	std::cout << sno << ". ";
	d.display();
	std::cout << " ";
	intime.display();
	std::cout << " ";
	outtime.display();
	std::cout << " " << mo << " " << " " << totaltime << " " << totalpay << " " << netpay << " " << "'" << notes << "'" << std::endl;
}



void Entry::write_text(std::ofstream& o) const
{
	o << sno << "* ";
	d.write_text(o);
	o << " ";
	intime.write_text(o);
	o << " ";
	outtime.write_text(o);
	o << " ";
	o << mo;
	o << " ";
	o << totaltime;
	o << " ";
	o << totalpay;
	o << " ";
	o << netpay;
	o << " ";
	o << notes;
}


void Entry::write_binary(std::ofstream& o) const
{
	o.write(reinterpret_cast<const char*>(&sno), sizeof(sno));
	d.write_binary(o);
	intime.write_binary(o);
	outtime.write_binary(o);
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

	int t_sno = 0, t_day = 0, t_month = 0, t_year = 0, t_inhour = 0, t_inmin = 0, t_outhour = 0, t_outmin = 0;
	char t_inap = 'n', t_outap = 'n';
	double t_mo = 0.0, t_totaltime = 0.0, t_totalpay = 0.0, t_netpay = 0.0;
	std::string t_notes;

	tokens >> t_sno >> t_day >> t_month >> t_year >> t_inhour >> t_inmin >> t_inap >> t_outhour >> t_outmin >> t_outap >> t_mo >> t_totaltime >> t_totalpay >> t_netpay >> t_notes;

	sno = t_sno;
	d.construct(t_month, t_day);
	intime.construct(t_inhour, t_inmin, t_inap);
	outtime.construct(t_outhour, t_outmin, t_outap);
	mo = t_mo;
	totaltime = t_totaltime;
	totalpay = t_totalpay;
	netpay = t_netpay;
	notes = t_notes;
}



void Entry::read_binary(std::ifstream& i)
{

	i.read(reinterpret_cast<char*>(&sno), sizeof(sno));
	d.read_binary(i);		
	intime.read_binary(i);	
	outtime.read_binary(i);	
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
		char c{ '0' };
}