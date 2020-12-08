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



void Entry::write_text(std::ostream& o) const
{
	o << sno << ". ";
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


void Entry::write_binary(std::ostream& o) const
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
	o.write(notes.c_str(), sizeof(size));
}


void Entry::read_text(std::istream& i)
{
	char dot{};
	i.read(reinterpret_cast<char*>(&sno), sizeof(sno));
	i >> dot;
	d.read_text(i);
	intime.read_text(i);
	outtime.read_text(i);
	i >> mo;
	i >> totaltime;
	i >> totalpay;
	i >> netpay;
	i >> notes;
}

void Entry::read_binary(std::istream& i)
{
	i.read(reinterpret_cast<char*>(&sno), sizeof(sno));
	intime.read_binary(i);
	outtime.read_binary(i);
	i.read(reinterpret_cast<char*>(&mo), sizeof(mo));
	i.read(reinterpret_cast<char*>(&totaltime), sizeof(totaltime));
	i.read(reinterpret_cast<char*>(&totalpay), sizeof(totalpay));
	i.read(reinterpret_cast<char*>(&netpay), sizeof(netpay));
	i.read(reinterpret_cast<char*>(&mo), sizeof(mo));
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
