// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
//  SPDX-License-Identifier: BSL-1.0
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>

#if !defined(HPX_WINDOWS)
#include <hpx/components/process/util/posix/initializers/initializer_base.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <unistd.h>

namespace hpx { namespace components { namespace process { namespace posix {

namespace initializers {

class bind_stdin : public initializer_base
{
public:
    explicit bind_stdin(const boost::iostreams::file_descriptor_source &source)
        : source_(source) {}

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        ::dup2(source_.handle(), STDIN_FILENO);
    }

private:
    boost::iostreams::file_descriptor_source source_;
};

}

}}}}

#endif
