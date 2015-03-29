var
  f,rank:array[1..50000] of longint;
  n,i,j,m,k,x,y,ans,t:longint;
function father(x:longint):longint;
begin
  if x=f[x] then exit(x);
  father:=father(f[x]);
  if rank[x]=rank[f[x]] then rank[x]:=0
    else if (rank[x]-rank[f[x]]=-2)or(rank[x]-rank[f[x]]=-1) then rank[x]:=1
      else if (rank[x]-rank[f[x]]=-1)or(rank[x]-rank[f[x]]=2) then rank[x]:=-1;
  f[x]:=father;
end;
begin
  fillchar(rank,sizeof(rank),0);
  readln(n,m);
  for i:=1 to n do f[i]:=i;
  ans:=0;
  for i:=1 to m do
    begin
      readln(k,x,y);
      if (x>n)or(y>n) then
        begin
          inc(ans);
          continue;
        end;
      if k=1 then
        begin
          if father(x)=father(y) then
            if rank[x]<>rank[y] then
              begin
                inc(ans);
                continue;
              end;
          t:=father(x);
          f[t]:=father(y);
          rank[t]:=rank[y];
        end;
      if k=2 then
        begin
          if father(x)=father(y) then
            if rank[x]=rank[y] then
              begin
                inc(ans);
                continue;
              end;
          t:=father(x);
          f[t]:=father(y);
          case rank[y] of
            0:rank[t]:=1;
            1:rank[t]:=-1;
            -1:rank[t]:=0;
          end;
        end;
    end;
  writeln(ans);
end.