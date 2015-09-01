// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2015 New Dream Network
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software
 * Foundation.  See file COPYING.
 *
 */

#include <stdint.h>

#include "include/rados/librgw.h"
#include "include/rados/rgw_file.h"

#include "gtest/gtest.h"
#include "common/ceph_argparse.h"
#include "common/debug.h"
#include "global/global_init.h"

namespace {

  librgw_t rgw;

}

TEST(LibRGW, INIT) {
  int ret;
  librgw_t rgw;

  ret = librgw_create(&rgw, NULL);
  ASSERT_EQ(ret, 0);


}

TEST(LibRGW, SHUTDOWN) {
  librgw_shutdown(rgw);
}

int main(int argc, char *argv[])
{
  vector<const char*> args;
  argv_to_vec(argc, (const char **)argv, args);

  global_init(NULL, args, CEPH_ENTITY_TYPE_CLIENT,
	      CODE_ENVIRONMENT_UTILITY, 0);
  common_init_finish(g_ceph_context);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
