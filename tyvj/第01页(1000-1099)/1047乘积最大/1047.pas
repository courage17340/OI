const maxn=50;maxk=20 ;
type num=record
       len:longint;
       s:array[1..maxn] of longint;
       end;
var n,k,i,j,l:integer;
    st,temps:string;
    m,tempm:num;
    f:array[1..maxn] of num;
    s1:array[1..maxn] of string;
procedure strtonum(str1:string;var num1:num);
var i:integer;
begin
 num1.len:=length(str1);
 for i:=1 to num1.len do
  num1.s[i]:=ord(str1[num1.len-i+1])-ord('0');
end;
procedure mult(x,y:num;var z: num );
var i,j,len:integer;
begin
fillchar(z,sizeof(z),0);
 for i:= 1 to x.len do
  for j:=1 to y.len do
   begin
    inc(z.s[i+j-1], x.s[i]*y.s[j]);
    inc(z.s[i+j],z.s[i+j-1] div 10);
    z.s[i+j-1]:=z.s[i+j-1] mod 10;
   end;
 len:=x.len+y.len+1;
 while (len>1) and (z.s[len]=0) do len:=len-1;
 z.len:=len;
end;
procedure bigger(x,y:num;var z:num);
var i:integer;
begin
 if x.len>y.len then begin z.len:=x.len;z.s:=x.s end else
 if x.len<y.len then begin z.len:=y.len;z.s:=y.s end else
  begin
   z.len:=x.len;
   i:=z.len;
   while (i>1) and (x.s[i]=y.s[i]) do i:=i-1;
   if x.s[i]>=y.s[i] then z.s:=x.s else z.s:=y.s;
 end;
end;
begin
 readln(n,k);
 readln(st);
 fillchar(f,sizeof(f),0);
 for i:=1 to n do
  begin
   s1[i]:=copy(st,1,i);
   strtonum(s1[i],f[i]);
  end;
 for i:=2 to k+1 do
  for j:=n downto i do
   begin
    fillchar(m,sizeof(m),0);
     for l:=i-1 to j-1 do
      begin
       temps:=copy(s1[j],l+1,j-l);
       strtonum(temps,tempm);
       mult(f[l],tempm, tempm);
       bigger(m,tempm,m);
      end;
    f[j]:=m;
  end;
l:=f[n].len;
while (l>1) and (f[n].s[l]=0) do l:=l-1;
 for i:=l downto 1 do write(f[n].s[i]);
writeln;
end.