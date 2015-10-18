﻿#include "writer.h"
#include "io_exception.h"

writer::writer(std::string filename)
{
    filename_ = filename;
}

writer::~writer()
{
    opened_file_.close();
}

std::streampos writer::get_file_size() const
{
    std::ofstream file(filename_, std::ifstream::ate | std::ifstream::binary);
    if (!file.good())
    {
            throw io_exception("Cannot open file");
    }

    return file.tellp();
}