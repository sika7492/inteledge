using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace dbConNet
{
    public partial class dbCon : Form
    {
        Dictionary<string, string> cmbDicData = new Dictionary<string, string>();

        public dbCon()
        {
            InitializeComponent();
        }

        private void bnConfirm_Click(object sender, EventArgs e)
        {
            tbCofirm.Text = "환영합니다.\r\n여기는 C# 확인용 텍스트입니다.";
        }

        private void bnRemove_Click(object sender, EventArgs e)
        {
            tbCofirm.Text = "";

            MessageBox.Show("텍스트가 제거되었습니다.");
        }

        private void ckbOpt10_CheckedChanged(object sender, EventArgs e)
        {
            if (ckbOpt10.Checked)
            {
                optFruit.Text += "사과 ";
            }
            else
            {
                optFruit.Text = optFruit.Text.Replace("사과 ", "");
            }
        }

        private void ckbOpt20_CheckedChanged(object sender, EventArgs e)
        {
            if (ckbOpt20.Checked)
            {
                optFruit.Text += "딸기 ";
            }
            else
            {
                optFruit.Text = optFruit.Text.Replace("딸기 ", "");
            }
        }

        private void rbRed_CheckedChanged(object sender, EventArgs e)
        {
            optColor.Text = (rbRed.Checked) ? "빨강" : "";
        }

        private void rbGreen_CheckedChanged(object sender, EventArgs e)
        {
            optColor.Text = (rbGreen.Checked) ? "초록" : "";
        }

        private void rbBlue_CheckedChanged(object sender, EventArgs e)
        {
            optColor.Text = (rbBlue.Checked) ? "파랑" : "";
        }

        private void rbNp_CheckedChanged(object sender, EventArgs e)
        {
            optLoc.Text = (rbNp.Checked) ? "북극" : "";
        }

        private void rbEq_CheckedChanged(object sender, EventArgs e)
        {
            optLoc.Text = (rbEq.Checked) ? "적도" : "";
        }

        private void rbSp_CheckedChanged(object sender, EventArgs e)
        {
            optLoc.Text = (rbSp.Checked) ? "남극" : "";
        }

        private void cmbDv_SelectedIndexChanged(object sender, EventArgs e)
        {
            tbCmbTxt.Text = cmbDv.SelectedItem.ToString();
        }

        private void lbBtnCnt_SelectedIndexChanged(object sender, EventArgs e)
        {
            string[] spBtn = lbBtnCnt.SelectedItem.ToString().Split(' ');

            tbBtnCnt.Text = spBtn[1];
        }

        private void dbCon_Load(object sender, EventArgs e)
        {
            
            cmbDicData.Clear();
            cmbDicData.Add("", "(선택)");
            cmbDicData.Add("25", "스마트팩토리실");
            cmbDicData.Add("20", "자동제어실");
            cmbDicData.Add("15", "프로그래밍01실");
            cmbDicData.Add("35", "프로그래밍02실");

            cmbDic.DataSource = new BindingSource(cmbDicData, null);
            cmbDic.DisplayMember = "Value";
            cmbDic.ValueMember = "Key";
            cmbDic.SelectedIndex = 0;

            timer1.Enabled = true;
        }

        private void cmbDic_SelectedIndexChanged(object sender, EventArgs e)
        {
            KeyValuePair<string, string> selectedPair = (KeyValuePair<string, string>)cmbDic.SelectedItem;
            tbKey.Text = selectedPair.Key + " 명";
            // tbValue.Text = selectedPair.Value;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            lblDate.Text = DateTime.Now.ToString("yyyy'년 'MM'월 'dd'일 :: 'HH'시 'mm'분 'ss'초'");
        }
    }
}
