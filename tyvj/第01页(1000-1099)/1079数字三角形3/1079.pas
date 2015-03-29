var
 a:array[0..25,0..25] of longint;
 i,j,n:longint;
function max(a,b:longint):longint;
begin max:=a;if a<b then max:=b;end;
begin
 readln(n);
 for i:=1 to n do
  begin
   for j:=1 to i do read(a[i,j]);
   readln;
  end;
 a[n div 2,n div 2]:=a[n div 2,n div 2]+99999999;
 for i:=2 to n do
  for j:=1 to i do a[i,j]:=max(a[i-1,j],a[i-1,j-1])+a[i,j];
 j:=0;
 for i:=1 to n do if a[n,i]>j then j:=a[n,i];writeln(j-99999999);
 readln;
end.