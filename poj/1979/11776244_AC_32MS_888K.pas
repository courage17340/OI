var
  a:array[0..21,0..21] of char;
  b:array[1..4,1..2] of longint=((0,1),(0,-1),(1,0),(-1,0));
  v:array[0..21,0..21] of boolean;
  n,m,i,j,ans,p,q:longint;
procedure search(x,y:longint);
var i:longint;
begin
  for i:=1 to 4 do
    if (x+b[i,1] in [1..n]) and (y+b[i,2] in [1..m]) and not (v[x+b[i,1],y+b[i,2]]) and (a[x+b[i,1],y+b[i,2]]='.') then
      begin
        v[x+b[i,1],y+b[i,2]]:=true;
        inc(ans);
        search(x+b[i,1],y+b[i,2]);
      end;
end;
begin
  for i:=0 to 21 do for j:=0 to 21 do a[i,j]:='#';
  while true do
    begin
      readln(m,n);
      if m=0 then break;
      ans:=1;
      for i:=1 to n do
        begin
          for j:=1 to m do
            begin
              read(a[i,j]);
              if a[i,j]='@' then begin p:=i;q:=j;end;
            end;
          readln;
        end;
      fillchar(v,sizeof(v),false);
      v[p,q]:=true;
      search(p,q);
      writeln(ans);
    end;
end.