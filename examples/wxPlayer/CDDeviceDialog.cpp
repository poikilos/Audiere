#ifdef _MSC_VER
#pragma warning(disable : 4786)
#endif

#include <audiere.h>
#include "CDDeviceDialog.h"


BEGIN_EVENT_TABLE(CDDeviceDialog, wxDialog)
  EVT_BUTTON(-1, CDDeviceDialog::OnButton)
END_EVENT_TABLE()


CDDeviceDialog::CDDeviceDialog(wxWindow* parent)
: wxDialog(parent, -1, wxString("New CD Device"))
{
  audiere::EnumerateCDDevices(m_devices);

  m_device = 0;
  m_explicit_device = 0;

  if (m_devices.size()) {
    m_device = new wxChoice(this, -1, wxDefaultPosition, wxSize(300, 22));
    for (size_t i = 0; i < m_devices.size(); ++i) {
      m_device->Append(m_devices[i].c_str());
    }
    m_device->SetSelection(0);
  } else {
    m_explicit_device = new wxTextCtrl(this, -1);
  }

  // button bar
  m_ok     = new wxButton(this, -1, "OK");
  m_cancel = new wxButton(this, -1, "Cancel");
  wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
  buttonSizer->Add(m_ok,     0, wxALIGN_CENTER | wxALL, 5);
  buttonSizer->Add(m_cancel, 0, wxALIGN_CENTER | wxALL, 5);

  // create vertical sizer
  wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
  if (m_device) {
    sizer->Add(
      m_device,
      0, wxALIGN_CENTER | wxALL, 5);
  }
  if (m_explicit_device) {
    sizer->Add(
      new wxStaticText(this, -1, "No devices found.  Please enter one."),
      0, wxALIGN_CENTER | wxALL, 5);
    sizer->Add(
      m_explicit_device,
      0, wxALIGN_CENTER | wxALL, 5);
  }
  sizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxALL, 4);

  SetAutoLayout(true);
  SetSizer(sizer);

  if (m_device) {
    m_device->SetFocus();
  }
  if (m_explicit_device) {
    m_explicit_device->SetFocus();
  }
  m_ok->SetDefault();

  sizer->Fit(this);
  sizer->SetSizeHints(this);
}


const std::string& CDDeviceDialog::getName() const {
  return m_name;
}


void CDDeviceDialog::OnButton(wxCommandEvent& event) {
  if (event.GetEventObject() == m_ok) {
    if (m_device) {
      int value = m_device->GetSelection();
      if (value < 0 || value >= static_cast<int>(m_devices.size())) {
	wxMessageBox("No device selected", "New CD Device", wxOK | wxICON_ERROR, this);
	return;
      }
      m_name = m_devices[value];
      EndModal(wxID_OK);
    }
    if (m_explicit_device) {
      m_name = m_explicit_device->GetValue();
      EndModal(wxID_OK);
    }
  } else {
    EndModal(wxID_CANCEL);
  }
}