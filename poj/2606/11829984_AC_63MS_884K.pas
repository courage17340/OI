type rec=record x,y:longint;end;
var
  a:array[1..200] of rec;
  n,i,j,k,s,ans:longint;
function yes(i,j,k:longint):boolean;
begin
  exit((a[i].y-a[j].y)*(a[i].x-a[k].x)=(a[i].y-a[k].y)*(a[i].x-a[j].x));
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i].x,a[i].y);
  ans:=0;
  for i:=1 to n-2 do
    for j:=i+1 to n-1 do
      begin
        s:=2;
        for k:=j+1 to n do
          if yes(i,j,k) then inc(s);
        if s>ans then ans:=s;
      end;
  writeln(ans);
  readln;
end.