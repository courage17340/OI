var
  a:array[1..4,1..4] of longint;
  i,j,n,ans:longint;
  ch:char;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;
begin
  for i:=1 to 4 do
    begin
      for j:=1 to 4 do
        begin
          read(ch);
          case ch of
            '0'..'9':a[i,j]:=ord(ch)-48;
            'A'..'F':a[i,j]:=ord(ch)-ord('A')+10;
            end;
        end;
      readln;
    end;
  ans:=0;
  for i:=1 to 4 do if a[i,1] in [0,1,2,3] then break;
  n:=i;
  for i:=1 to 3 do
    for j:=1 to 3 do
      if a[n,j]>a[n,j+1]
        then
          begin
            inc(ans);
            swap(a[n,j],a[n,j+1]);
          end;
  for j:=1 to 4 do if a[1,j] in [0,1,2,3] then break;
  n:=j;
  for i:=1 to 3 do
    for j:=1 to 3 do
      if a[j,n]>a[j+1,n]
        then
          begin
            inc(ans);
            swap(a[j,n],a[j+1,n]);
          end;
  writeln(ans);
end.