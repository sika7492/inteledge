using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Globalization;
using System.Xml;
using System.Xml.Linq;
using MySqlConnector;

namespace poseprj.Popup
{
    public partial class SignIn : Form
    {
        private string svr_IP;
        private string DBname;
        private string DBport;
        private string XmlUser;
        private string Loc;

        private string ConString;           // 현재 string 값
        private string LocalConstring;      //
        private string remoteConstring;



        public SignIn()
        {
            InitializeComponent();
        }

        private void SignIn_Load(object sender, EventArgs e)
        {
            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(@".\Sys.Config");
            XmlElement root = xmlDoc.DocumentElement;

            // 노드요소들
            XmlNodeList nodes = root.ChildNodes;

            foreach (XmlNode node in nodes)
            {
                switch (node.Name)
                {
                    case "Loc":
                        Loc = node.InnerText;
                        break;
                    case "Remote":
                        svr_IP = node.InnerText;
                        break;
                    case "DBname":
                        DBname = node.InnerText;
                        break;
                    case "DBport":
                        DBport = node.InnerText;
                        break;
                    case "User":
                        XmlUser = node.InnerText;
                        break;
                }

            }

            LocalConstring = $@" Server=localhost;Port={DBport};DATABASE={DBname};UID=iphak;PASSWORD=usr123; ";

            // MessageBox.Show(LocalConstring);

            remoteConstring = $@" Server={svr_IP};Port={DBport};DATABASE={DBname};UID=iphak;PASSWORD=usr123; ";

            // MessageBox.Show(remoteConstring);

            ConString = (Loc == "LOCAL") ? LocalConstring : remoteConstring;

            // mxl text 용 코드
            // MessageBox.Show("[" + svr_IP + ":" + DBname + ":" + DBport + ";" + User + "]");

            if (XmlUser == "")
            {
                ckbsave.Checked = false;
                txtuser.Enabled = true;

                txtuser.Text = "";
                txtuser.Focus();
            }
            else
            {
                ckbsave.Checked = true;
                txtuser.Enabled = false;

                txtuser.Text = XmlUser;
                txtpwd.Focus();
            }

            timer1.Enabled = true;
        }


        private void timer1_Tick(object sender, EventArgs e)
        {
            CultureInfo cultures = CultureInfo.CreateSpecificCulture("ko-KR");

            string timeStr = DateTime.Now.ToString(string.Format("yyyy년 M월 dd일 (ddd)\r\ntt hh:mm:sss", cultures));

            txdate.Text = timeStr;

        }

        private void ckbsave_CheckedChanged(object sender, EventArgs e)
        {
            if (ckbsave.Checked == false)
            {
                txtuser.Text = "";
                txtuser.Enabled = true;

                txtuser.Focus();

            }
            else
            {

                XmlDocument sysConfig = new XmlDocument();
                sysConfig.Load(@".\Sys.Config");

                XmlNode nodeUser = sysConfig.DocumentElement.SelectSingleNode("/DBinfs/User");

                nodeUser.InnerText = txtuser.Text.Replace("\r\n", "");

                sysConfig.Save(@".\Sys.Config");

                txtuser.Enabled = false;
                txtpwd.Focus();
            }

        }

        private void txtuser_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                txtpwd.Focus();
            }
        }

        private void txtpwd_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {

                bnlogin.Focus();



            }

        }

        private void bnlogin_Click(object sender, EventArgs e)
        {
            if (txtuser.Text == "" || txtpwd.Text == "") 
            {
                MessageBox.Show("사용자 id 혹은 비밀번호를 입력하세요");
                return;
            }
            MySqlConnection con = new MySqlConnection(ConString);
            string sSQL = $@"SELECT usrid, usralias, kind, auth F
                             FROM usr
                             WHERE usrid = '{txtuser.Text}'
                             AND usrpwd = password('{txtpwd.Text}') ";

            try
            {
                con.Open();
                MySqlCommand cmd = new MySqlCommand(sSQL, con);

                var Read = cmd.ExecuteReader();

                if (Read.Read())
                {
                    MessageBox.Show("DB 진입이 인정되었습니다.");
                }
                else
                {
                    MessageBox.Show("사용자 승인여부를 시스템 관리자에게 문의하세요.");
                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                con.Close();
            }
        }
    }
}
