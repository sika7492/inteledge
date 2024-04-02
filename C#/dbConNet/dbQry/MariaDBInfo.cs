using MySqlConnector;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using static System.ComponentModel.Design.ObjectSelectorEditor;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace dbQry
{
    class MariaDBInfo
    {
        private string ip;
        private int port;
        private string uid;
        private string pwd;
        private string dbname;
        private MySqlConnection conn;

        public MariaDBInfo(string ip, int port, string uid
                                        , string pwd, string dbname)
        {
            this.ip = ip;
            this.port = port;
            this.uid = uid;
            this.pwd = pwd;
            this.dbname = dbname;
            this.conn = null;
        }

        public void initDB()
        {
            // CharSet=utf8 설정을 안하면 한글 입출력시 물음표(?)로 인식
            string connectString
                = $"Server={ip};Port={port};Database={dbname};Uid={uid};Pwd={pwd};CharSet=utf8;";
            try
            {
                conn = new MySqlConnection(connectString);  // DB 설정
                conn.Open();    // DB 연결
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }

        public MySqlConnection getConnection()
        {
            if (conn == null)
                initDB();
            return conn;
        }
    }

    class MyData
    {
        private string stdid;
        private string stdnm;
        private string tG;
        private string typGubun;
        private string gender;
        private string sj01;
        private string sj02;
        private string sj;
        private string rk;

        public MyData(string stdid, string stdnm, string tG, string typGubun, string gender, 
                        string sj01, string sj02, string sj, string rk)
        {
            this.stdid = stdid;
            this.stdnm = stdnm;
            this.tG = tG;
            this.typGubun = typGubun;
            this.gender = gender;
            this.sj01 = sj01;
            this.sj02 = sj02;
            this.sj = sj;
            this.rk = rk;
        }
    }

    class MariaDBManager
    {
        MariaDBInfo dbinfo;

        public MariaDBManager(MariaDBInfo mInfo)
        {
            dbinfo = mInfo;
        }

        public List<MyData> selectQry(string query)
        {
            List<MyData> result = new List<MyData>();

            MySqlCommand cmd = new MySqlCommand(query, dbinfo.getConnection());
            MySqlDataReader dr = cmd.ExecuteReader();

            try
            {
                result.Clear();

                while (dr.Read())
                {
                    // 데이터 조회시 null 값이 있을 경우에는 예외처리 필요.
                    // MessageBox.Show(dr["stdid"].ToString());

                    result.Add(new MyData(dr["stdid"].ToString(), dr["stdnm"].ToString(), dr["tG"].ToString(),
                                             dr["typGubun"].ToString(), dr["gender"].ToString(), dr["sj01"].ToString(),
                                             dr["sj02"].ToString(), dr["sj"].ToString(), dr["rk"].ToString()));                    
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
                return null;
            }
            finally
            {
                dr.Close();
            }
            return result;
        }
    }
}
