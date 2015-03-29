const
dx:array[1..4] of -1..1=(-1,0,1,0);
   dy:array[1..4] of -1..1=(0,1,0,-1);
var
  s:string;
  pic:array[1..50,1..79] of byte;
  bz:array[1..50,1..79] of boolean;
  m,n,i,j,num:integer;
  h:array[1..4000,1..2] of byte;
procedure doing(p,q:integer);
 var i,t,w,x,y:integer;
 begin
  inc(num);bz[p,q]:=false;
  t:=1;w:=1;h[1,1]:=p;h[1,2]:=q;
  repeat
   for i:=1 to 4 do
    begin
     x:=h[t,1]+dx[i];y:=h[t,2]+dy[i];
     if (x>0) and (x<=m) and (y>0) and (y<=n) and bz[x,y]
      then begin inc(w);h[w,1]:=x;h[w,2]:=y;bz[x,y]:=false;end;
    end;
    inc(t); 
  until t>w;
 end;
begin
  fillchar(bz,sizeof(bz),true);
num:=0;
  readln(m,n);
  for i:=1 to m do
   begin
     readln(s);
     for j:=1 to n do
      begin
       pic[i,j]:=ord(s[j])-ord('0');
       if pic[i,j]=0 then bz[i,j]:=false;
      end;
   end;
  for i:=1 to m do
   for j:=1 to n do if bz[i,j] then doing(i,j);
  writeln(num);
end.