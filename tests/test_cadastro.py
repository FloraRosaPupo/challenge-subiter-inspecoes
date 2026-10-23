import subprocess
import unittest
import os

class CadastroTests(unittest.TestCase):
    def run_program(self,text):
        return subprocess.run([os.environ.get('CADASTRO_BIN','./cadastro')],input=text,text=True,capture_output=True,check=True,timeout=5).stdout

    def test_nome_e_descricao_com_espacos(self):
        out=self.run_program('1\nBomba de agua\nEQ 01\n42\nInstalada no setor A\n2\n0\n')
        self.assertIn('Nome: Bomba de agua',out)
        self.assertIn('Descricao: Instalada no setor A',out)

    def test_recupera_entrada_invalida(self):
        out=self.run_program('abc\n2\n0\n')
        self.assertIn('inteiro valido',out)
        self.assertIn('Nenhum equipamento',out)

    def test_eof_nao_causa_loop(self):
        self.run_program('1\nNome\n')

    def test_limite(self):
        out=self.run_program(('1\nNome\nCodigo\n1\nDescricao\n'*3)+'1\n0\n')
        self.assertIn('Limite de 3 equipamentos',out)

if __name__=='__main__': unittest.main()
