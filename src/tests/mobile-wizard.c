// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2018 - 2021 Red Hat, Inc.
 */

#include "nm-default.h"
#include "nma-private.h"

#include <gtk/gtk.h>
#include "nma-mobile-wizard.h"

static void
wizard_cb (NMAMobileWizard *self, gboolean canceled, NMAMobileWizardAccessMethod *method, gpointer user_data)
{
	gtk_main_quit ();
}

int
main (int argc, char *argv[])
{
	NMAMobileWizard *wizard;

	gtk_init ();

	wizard = nma_mobile_wizard_new (NULL, NULL, NM_DEVICE_MODEM_CAPABILITY_NONE, TRUE, wizard_cb, NULL);

	nma_mobile_wizard_present (wizard);
	gtk_main ();
	nma_mobile_wizard_destroy (wizard);
}
