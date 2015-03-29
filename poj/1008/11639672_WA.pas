var
  a:array[1..19] of string;
  b:array[1..20] of string;
  c:array[1..260] of string;
  n,i,j,k:longint;
  s:string;
procedure init;
var
  i,j,p,q:longint;
  s:string;
begin
  a[1]:='pop';
  a[2]:='no';
  a[3]:='zip';
  a[4]:='zotz';
  a[5]:='tzec';
  a[6]:='xul';
  a[7]:='yoxkin';
  a[8]:='mol';
  a[9]:='chen';
  a[10]:='yax';
  a[11]:='zac';
  a[12]:='ceh';
  a[13]:='mac';
  a[14]:='kankin';
  a[15]:='muan';
  a[16]:='pax';
  a[17]:='koyab';
  a[18]:='cumhu';
  a[19]:='uayet';

  b[1]:='imix';
  b[2]:='ik';
  b[3]:='akbal';
  b[4]:='kan';
  b[5]:='chicchan';
  b[6]:='cimi';
  b[7]:='manik';
  b[8]:='lamat';
  b[9]:='muluk';
  b[10]:='ok';
  b[11]:='chuen';
  b[12]:='eb';
  b[13]:='ben';
  b[14]:='ix';
  b[15]:='mem';
  b[16]:='cib';
  b[17]:='caban';
  b[18]:='eznab';
  b[19]:='canac';
  b[20]:='ahau';

  p:=0;
  q:=0;
  for i:=1 to 260 do
    begin
      inc(p);if p=14 then p:=1;
      inc(q);if q=21 then q:=1;
      str(p,s);
      c[i]:=s+' '+b[q];
    end;
end;

function f(s:string):longint;
var
  s1:string;
  d,m,y,i,j:longint;
begin
  s1:=copy(s,1,pos('.',s)-1);
  delete(s,1,pos(' ',s));
  val(s1,d);
  s1:=copy(s,1,pos(' ',s)-1);
  delete(s,1,pos(' ',s));
  val(s,y);
  for m:=1 to 19 do if a[m]=s1 then break;
  f:=y*365+(m-1)*20+d+1;
end;

function g(num:longint):string;
var
  y,d:longint;
begin
  y:=num div 260;
  d:=num mod 260;
  str(y,g);
  g:=c[d]+' '+g;
end;

begin
  init;
  readln(n);
  writeln(n);
  for i:=1 to n do
    begin
      readln(s);
      writeln(g(f(s)));
    end;
end.