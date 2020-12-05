#pragma once

template <typename T>
class Factory
{
private:
    std::vector<std::shared_ptr<Figure<T>>> vct;
    std::vector<std::pair<std::shared_ptr<Figure<T>>, std::string>> cmd_vct;
public:
    using value_type = T;
    Factory() {}
    void exec_cmd(std::istream&);
    std::shared_ptr<Figure<T>> create(std::istream&);
};

template <typename T>
std::shared_ptr<Figure<T>> Factory<T>::create(std::istream& is)
{
    std::string name;
    is >> name;
    if (name == "square" || name == "Square:") { return std::shared_ptr<Figure<T>> (new Square<T>(is)); }
    else if (name == "triangle" || name == "Triangle:") { return std::shared_ptr<Figure<T>> (new Triangle<T>(is)); }
    else if (name == "octagon" || name == "Octagon:")  { return std::shared_ptr<Figure<T>> (new Octagon<T>(is)); }
    else { throw std::logic_error("There is no such figure"); }
}

template <typename T>
void Factory<T>::exec_cmd(std::istream& is)
{
    std::string name = "start";
    std::cout << "Enter name of cmd <add/del/clear/print/undo/save/usage/exit>\n";
    while(name != "exit" && !is.eof())
    {
        is >> name;
        if(name == "usage")
        {
            std::cout << "add->square/octagon/triangle->3/4/8 points\n";
            std::cout << "del->index\n";
            std::cout << "undo\n";
            std::cout << "print\n";
            std::cout << "exit\n";
        }
        else if(name == "add")
        {
            std::cout << "Enter name of figure <square/octagon/triangle>\n";
            try
            {
                vct.push_back(this->create(is));
                std::pair p{vct.back(),"a"};
                cmd_vct.push_back(p);
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n';  }
        }
        else if(name == "del")
        {
            try
            {
                size_t ind = 0;
                std::cout << "Enter index of figure\n";
                is >> ind;
                if(ind >= vct.size()) { throw std::exception("Index out of boundes"); }
                std::pair p{vct.back(),"d"};
                cmd_vct.push_back(p);
                vct.erase(vct.begin()+ind);
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n';  }
        }
        else if(name == "clear")
        {
            try
            {
                for(auto& el: vct) { cmd_vct.push_back({el, "d"}); }
                vct.clear();
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n';  }
        }
        else if(name == "undo")
        {
            try
            {
                if(!cmd_vct.empty())
                {
                    if(cmd_vct.back().second == "a") { vct.pop_back(); }
                    else if(cmd_vct.back().second == "d") { vct.push_back(cmd_vct.back().first); }
                    else { throw std::logic_error("No such command"); }
                    cmd_vct.pop_back();
                }
                else { throw std::logic_error("No operations for undo"); }
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n';  }
        }
        else if(name == "print")
        {
            try
            {
                if(vct.empty()) { throw std::logic_error("No figures"); }
                for(auto& el: vct)
                {
                    el->print_figure();
                    std::cout << "center x: " << el->center().x_ << " y: " << el->center().y_ << "\n";
                    std::cout << "area:" << el->area() << "\n";
                }
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
        }
        else if(name == "save")
        {
            try
            {
                std::string filename;
                std::cout << "Input save filename\n";
                std::cin >> filename;
                Document<T> doc;
                doc.save(filename, vct);
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

        }
        else if(name == "load")
        {
            try
            {
                std::string filename;
                std::cout << "Input load filename\n";
                std::cin >> filename;
                Document<T> doc;
                doc.load(filename, vct);
            }
            catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

        }
    }
}
