#pragma once

template <typename T>
class Document
{
private:
    Factory<T> factory;
public:
    void save(std::string const&, std::vector<std::shared_ptr<Figure<T>>> const&);
    void load(std::string const&, std::vector<std::shared_ptr<Figure<T>>>&);
};

template <typename T>
void Document<T>::save(std::string const& filename, std::vector<std::shared_ptr<Figure<T>>> const& vct)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) { throw std::runtime_error("File is not opened"); }
    fout << vct.size() << '\n';
    for (auto& el: vct) { el->print_figure(fout); }
}

template <typename T>
void Document<T>::load(std::string const& filename, std::vector<std::shared_ptr<Figure<T>>>& vct)
{
    std::ifstream finp;
    size_t size = 0;
    vct.clear();
    finp.open(filename);
    if (!finp.is_open()) { throw std::runtime_error("File is not opened"); }
    finp >> size;
    for(size_t i = 0; i < size; ++i) { vct.push_back(factory.create(finp)); }
}
