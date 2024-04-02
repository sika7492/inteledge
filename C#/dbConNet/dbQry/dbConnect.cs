using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySqlConnector;

namespace dbQry
{
    public partial class dbConnect : Form
    {
        MariaDBInfo mInfo = new MariaDBInfo("localhost", 3306,  "your_username", "your_password","your_dbname");
        string query;

        public dbConnect()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MySqlConnection msConn;
            msConn = mInfo.getConnection();

            tbMsg.Text = (msConn == null) ? "연결 실패" : "DB에 연결되었습니다.";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                MariaDBManager mDBmanager = new MariaDBManager(mInfo);
                List<MyData> myLists = new List<MyData>();

                query = $@"WITH e01 AS (SELECT stdid, round(SUM(clsScr),1) sj01  FROM evtScore01 GROUP BY stdid), 
  e02 AS (SELECT stdid, round(SUM(clsscr),1) sj02 FROM evtScore02 GROUP BY stdid)

SELECT 
  s.stdid, 
  s.stdnm, 
  CASE 
    WHEN typGubun = '일반전형 대상자' THEN 1
    WHEN typGubun = '사회통합 대상자' THEN 2
    ELSE 3 
  END tG, 
  S.typGubun, 
  s.gender,
  e01.sj01, 
  e02.sj02, 
  ifnull(e01.sj01,0) + ifnull(e02.sj02,0) sj,
  RANK() OVER(
    PARTITION BY typGubun
    ORDER BY (ifnull(e01.sj01,0) + ifnull(e02.sj02,0)) DESC
  ) rk
FROM  
  stdinf s 
  INNER JOIN e01 ON(s.stdid = e01.stdid)
  LEFT JOIN e02 ON(s.stdid = e02.stdid)
ORDER BY 
  tG, 
  rk;
";

                myLists = mDBmanager.selectQry(query);
                tbMsg.Text = myLists.Count.ToString() + " 건이 조회되었습니다.";

                foreach (var myList in myLists)
                {
                    // MessageBox.Show(myList.ToString());
                }
            }
            catch (Exception ex)
            {
                tbMsg.Text = "오류가 발생했습니다: " + ex.Message;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            tbMsg.Text = query;
        }

        private void dbConnect_Load(object sender, EventArgs e)
        {

        }
    }
}
